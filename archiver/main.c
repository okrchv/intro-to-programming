#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "archiver.h"

int main(int argc, char **argv) {
    int opt;
    // parse cli arguments,
    // define -c, -x flags as required with input data after
    while ((opt = getopt(argc, argv, "c:x:")) != -1) {
        switch (opt) {
            case 'c': {
                argv += optind;
                printf("Creating %s\n", optarg);

                write_archive(optarg, (const char **)argv);

                break;
            }
            case 'x': {
                argv += optind;
                printf("Extracting %s\n", optarg);

                extract_archive(optarg);

                break;
            }
            default:
                fprintf(stderr, "Usage: %s [-cx] [file...]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    return 0;
}
