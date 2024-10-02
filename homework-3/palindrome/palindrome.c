#include <stdio.h>
#include <stdlib.h>

unsigned int reverseBits(int inputNum) {
    unsigned int reversedInputNum = 0;

    while (inputNum > 0) {
        reversedInputNum <<= 1;

        if (inputNum & 1) {
            reversedInputNum ^= 1;
        }

        inputNum >>= 1;
    }

    return reversedInputNum;
}

int main(void) {
    unsigned int inputNum;

    printf("Enter number: \n");
    if (scanf(" %d", &inputNum) != 1) {
        printf("Error: Invalid input.");
        exit(1);
    }

    if (inputNum == reverseBits(inputNum)) {
        printf("Your number is a palindrome.");
    } else {
        printf("Your number is NOT a palindrome.");
    }

    return 0;
}
