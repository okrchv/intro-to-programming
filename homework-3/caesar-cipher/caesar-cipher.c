#include <ctype.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int getCharNumToEncrypt(void) {
    int charNumToEncrypt;

    printf("Enter the number of characters to encrypt:\n");
    if (scanf(" %d", &charNumToEncrypt) != 1 || charNumToEncrypt <= 0) {
        printf("Error: Invalid input.");
        exit(1);
    }
    fflush(stdin);

    return charNumToEncrypt;
}

// Generate a random encryption key in the range [-256 to 256]
int getEncryptKey(void) {
    srand(time(NULL));

    int encryptKey = (rand() % 513) - 256;

    return encryptKey;
}

char getEncryptedChar(char inputChar, int encryptKey) {
    char inputLetter = inputChar - 'a';
    char encryptedLetter = (inputLetter + encryptKey) % 26;

    char encryptedChar = encryptedLetter >= 0
        ? 'a' + encryptedLetter
        : 'z' + encryptedLetter + 1;

    return encryptedChar;
}

int main() {
    int charNumToEncrypt = getCharNumToEncrypt();

    int encryptKey = getEncryptKey();
    printf("Generated encryption key: %d\n", encryptKey);

    for (int i = 1; i <= charNumToEncrypt; i++) {
        printf("Enter character %d\n", i);

        while (1) {
            char letter;
            scanf("%c", &letter);
            fflush(stdin);

            if (isalpha(letter)) {
                letter = tolower(letter);

                char encryptedChar = getEncryptedChar(letter, encryptKey);
                printf("Encrypted character: %c\n", encryptedChar);

                break;
            } else {
                printf("Error: Invalid input. Please, try again:\n");
            }
        }
    }

    return 0;
}
