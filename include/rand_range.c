#include <time.h>
#include <stdlib.h>

#include "rand_range.h"

void initRand() {
    srand(time(NULL));
}

int randInRange(int limit) {
    int element = (rand() % limit);
    return element;
}
