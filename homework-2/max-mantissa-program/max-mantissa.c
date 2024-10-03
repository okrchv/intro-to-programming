#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint32_t maxExponent = ((1 << 8) - 2); // 8 exponent bits
    printf("max Exponent: %d \n", maxExponent);

    uint32_t maxMantissa = ((1 << 23) - 1); // 23 mantissa bit
    printf("max Mantissa: %d \n", maxMantissa);

    float maxMantissaValue = 1 + 1 - (1.0 / (1 << 23)); // 23 mantissa bit's value: 1 + (2^23 − 1) * 2^−23 = 1 + 1 - 2^-23
    printf("max Mantissa Value: %.25f \n", maxMantissaValue);

    uint32_t maxFloatAsInt = (maxExponent << 23 | maxMantissa); // 32bit all together 01111111011111111111111111111111
    float maxFloat = *(float*)&maxFloatAsInt;
    printf("The largest representable 32-bit floating-point number: %f \n", maxFloat);
}
