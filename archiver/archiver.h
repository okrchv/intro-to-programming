#ifndef ARCHIVER_H
#define ARCHIVER_H

void write_archive(const char *outname, const char **filename);

void extract_archive(const char *filename);

#endif
