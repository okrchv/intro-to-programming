#include <stdint.h>
#include <stdio.h>

float invertSign(float inputNum) {
    uint32_t inputNumAsInt = *(uint32_t*)&inputNum;

    uint32_t mask = (1 << 31);

    uint32_t invertedNumAsInt = (inputNumAsInt ^ mask);

    float invertedNum = *(float*)&invertedNumAsInt;

    return invertedNum;
}

int main(void) {
    float inputNum;

    printf("Please enter float number: \n");
    scanf("%f", &inputNum);

    float invertedNum = invertSign(inputNum);

    printf("Reversed number for your input: \n%f", invertedNum);

    return 0;
}
