#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point {
    int x;
    int y;
} point_t;

typedef struct Polygon {
    char name[128];
    int length;
    point_t *points;
} polygon_t;

void print_polygon(const polygon_t *polygon) {
    printf("Polygon: %s\n", polygon->name);

    printf("Points: ");

    for (int i = 0; i < polygon->length; ++i) {
        printf("(%d, %d)", polygon->points[i].x, polygon->points[i].y);

        if (i < polygon->length - 1) {
            printf("; ");
        }
    }

    printf("\n\n");
}

int main(void) {
    FILE *file = fopen("./polygons.txt", "r");

    if (!file) {
        fprintf(stderr, "Error occurred while opening file (%s)",
                strerror(errno));

        exit(1);
    }

    polygon_t *polygons = NULL;
    int count = 0;

    for (;;) {
        polygon_t polygon;

        if (fscanf(file, "%s", polygon.name) != 1) {
            // fprintf(stderr, "Failed to read polygon name (%s)\n",
            // strerror(errno));
            break;
        }

        if (fscanf(file, "%d", &polygon.length) != 1) {
            fprintf(stderr, "Failed to read points of %s (%s)\n", polygon.name,
                    strerror(errno));
            break;
        }

        polygon.points = malloc(polygon.length * sizeof(point_t));

        if (!polygon.points) {
            fprintf(stderr, "Failed to allocate memory (%s)\n",
                    strerror(errno));
            break;
        }

        for (int i = 0; i < polygon.length; ++i) {
            if (fscanf(file, "%d %d", &polygon.points[i].x,
                       &polygon.points[i].y) != 2) {
                fprintf(stderr, "Failed to read point of %s (%s)\n",
                        polygon.name, strerror(errno));

                free(polygon.points);
                break;
            }
        }

        polygon_t *new_arr = realloc(polygons, (count + 1) * sizeof(polygon_t));

        if (!new_arr) {
            fprintf(stderr, "Failed to reallocate memory (%s)",
                    strerror(errno));

            free(polygon.points);
            break;
        }

        polygons = new_arr;
        polygons[count] = polygon;
        count++;
    }

    fclose(file);

    for (int i = 0; i < count; i++) {
        print_polygon(&polygons[i]);

        free(polygons[i].points);
    }

    free(polygons);

    return 0;
}
