#include "archiver.h"

#include <archive.h>
#include <archive_entry.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void handle_file(const char *filename, struct stat *st, struct archive *a,
                 struct archive_entry *entry) {
    printf("Adding file %s\n", filename);

    char buff[8192];
    int len;
    int fd;

    // adding file metadata to the archive
    archive_entry_set_pathname(entry, filename);
    archive_entry_set_size(entry, st->st_size);  // the same as (*st).st_size
    archive_entry_set_filetype(entry, AE_IFREG);
    archive_entry_copy_stat(entry, st);
    archive_write_header(a, entry);
    archive_entry_clear(entry);

    // adding file contents to the archive
    fd = open(filename, O_RDONLY);
    len = read(fd, buff, sizeof(buff));
    while (len > 0) {
        archive_write_data(a, buff, len);
        len = read(fd, buff, sizeof(buff));
    }
    close(fd);
}

void handle_dir(const char *pathname, struct stat *st, struct archive *a,
                struct archive_entry *entry) {
    printf("Adding dir %s\n", pathname);

    archive_entry_set_pathname(entry, pathname);
    archive_entry_set_filetype(entry, AE_IFDIR);
    archive_entry_copy_stat(entry, st);
    archive_write_header(a, entry);
    archive_entry_clear(entry);

    DIR *d = opendir(pathname);  // open the path
    struct dirent *de;
    char *entry_path;

    while ((de = readdir(d)) != NULL) {
        if (!strcmp(de->d_name, ".") || !strcmp(de->d_name, "..")) {
            continue;
        }

        //???: malloc will preserve previously set chars — why?
        entry_path = calloc(1024, sizeof(char));

        strcat(entry_path, pathname);
        strcat(entry_path, "/");
        strcat(entry_path, de->d_name);
        strcat(entry_path, "\0");

        stat(entry_path, st);

        if (S_ISDIR(st->st_mode)) {
            handle_dir(entry_path, st, a, entry);
        } else if (S_ISREG(st->st_mode)) {
            handle_file(entry_path, st, a, entry);
        }

        free(entry_path);
    }
}

void write_archive(const char *outname, const char **filename) {
    struct stat *st;
    struct archive *a;
    struct archive_entry *entry;

    st = malloc(sizeof(struct stat));
    a = archive_write_new();
    entry = archive_entry_new();

    archive_write_add_filter_gzip(a);            // compression
    archive_write_set_format_pax_restricted(a);  // archive format
    archive_write_open_filename(a, outname);

    while (*filename) {
        stat(*filename, st);

        // decide if we are working with dir or file
        if (S_ISDIR(st->st_mode)) {
            handle_dir(*filename, st, a, entry);
        } else if (S_ISREG(st->st_mode)) {
            handle_file(*filename, st, a, entry);
        }

        filename++;
    }

    archive_entry_free(entry);
    archive_write_close(a);
    archive_write_free(a);
    free(st);
}

int copy_data(struct archive *ar, struct archive *aw) {
    int res;
    const void *buff;
    size_t size;
    la_int64_t offset;

    for (;;) {
        res = archive_read_data_block(ar, &buff, &size, &offset);
        if (res == ARCHIVE_EOF) return (ARCHIVE_OK);
        if (res < ARCHIVE_OK) return (res);

        res = archive_write_data_block(aw, buff, size, offset);
        if (res < ARCHIVE_OK) {
            fprintf(stderr, "%s\n", archive_error_string(aw));
            return (res);
        }
    }
}

void extract_archive(const char *filename) {
    struct archive *a;    // for reading
    struct archive *ext;  // for writing
    struct archive_entry *entry;
    int flags;
    int res;

    // Select which attributes we want to restore.
    flags = ARCHIVE_EXTRACT_TIME;
    flags |= ARCHIVE_EXTRACT_PERM;
    flags |= ARCHIVE_EXTRACT_ACL;
    flags |= ARCHIVE_EXTRACT_FFLAGS;

    a = archive_read_new();

    archive_read_support_format_tar(a);   // archive format
    archive_read_support_filter_gzip(a);  // compression

    ext = archive_write_disk_new();

    archive_write_disk_set_options(ext, flags);
    archive_write_disk_set_standard_lookup(ext);

    if ((res = archive_read_open_filename(a, filename, 10240))) {
        exit(1);
    }

    for (;;) {
        res = archive_read_next_header(a, &entry);
        if (res == ARCHIVE_EOF) break;
        if (res < ARCHIVE_OK) fprintf(stderr, "%s\n", archive_error_string(a));
        if (res < ARCHIVE_WARN) exit(1);

        res = archive_write_header(ext, entry);
        if (res < ARCHIVE_OK) {
            fprintf(stderr, "%s\n", archive_error_string(ext));
        } else if (archive_entry_size(entry) > 0) {
            res = copy_data(a, ext);
            if (res < ARCHIVE_OK) {
                fprintf(stderr, "%s\n", archive_error_string(ext));
            }
            if (res < ARCHIVE_WARN) exit(1);
        }

        res = archive_write_finish_entry(ext);
        if (res < ARCHIVE_OK) {
            fprintf(stderr, "%s\n", archive_error_string(ext));
        }
        if (res < ARCHIVE_WARN) exit(1);
    }

    archive_read_close(a);
    archive_read_free(a);
    archive_write_close(ext);
    archive_write_free(ext);
}
