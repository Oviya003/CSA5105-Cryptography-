
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100];
    int a, b, i, p, c;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter values of a and b: ");
    scanf("%d %d", &a, &b);

    if (a < 0 || a >= 26 || b < 0 || b >= 26 ||
        (a % 2 == 0 && a != 0) ||
        a == 0 || a == 13) {
        printf("Invalid key values.\n");
        return 0;
    }

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            p = toupper((unsigned char)text[i]) - 'A';
            c = (a * p + b) % 26;
            text[i] = c + 'A';
        }
    }

    printf("Ciphertext: %s", text);
    return 0;
}

