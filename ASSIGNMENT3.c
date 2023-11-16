#include <stdio.h>
#include <string.h>

int main() {
    // a. Identification of Vowels and Consonants
    char ch;
    int vowels = 0, consonants = 0;

    printf("a. Enter a string for Vowels and Consonants: ");
    while ((ch = getchar()) != '\n') {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    printf("Vowels: %d\nConsonants: %d\n\n", vowels, consonants);

    // b. Count number of vowels and consonants
    vowels = 0;
    consonants = 0;

    printf("b. Enter a string for counting vowels and consonants: ");
    while ((ch = getchar()) != '\n') {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    printf("Vowels: %d\nConsonants: %d\n\n", vowels, consonants);

    // c. Count the number of Lines in given input
    int lineCount = 0;

    printf("c. Enter text (Ctrl+D to end input):\n");
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }
    }

    printf("Number of lines: %d\n\n", lineCount);

    // d. Recognize strings ending with 00
    char str[100];

    printf("d. Enter a string for recognizing ending with 00: ");
    scanf("%s", str);

    if (strlen(str) >= 2 && str[strlen(str) - 2] == '0' && str[strlen(str) - 1] == '0') {
        printf("String ending with 00: %s\n\n", str);
    } else {
        printf("String does not end with 00.\n\n");
    }

    // e. Recognize a string with three consecutive 0’s
    printf("e. Enter a string for recognizing three consecutive 0's: ");
    scanf("%s", str);

    if (strstr(str, "000") != NULL) {
        printf("String with three consecutive 0's: %s\n", str);
    } else {
        printf("String does not contain three consecutive 0's.\n");
    }

    return 0;
}
