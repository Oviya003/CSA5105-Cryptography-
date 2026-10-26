
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[1000];
    int a, b, i, c, p, inv;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter a and b (candidate key): ");
    scanf("%d %d", &a, &b);

    inv = -1;
    for (i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            inv = i;
            break;
        }
    }

    if (inv == -1) {
        printf("Invalid value of a.\n");
        return 0;
    }

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            c = toupper((unsigned char)text[i]) - 'A';
            p = (inv * (c - b + 26)) % 26;
            text[i] = p + 'A';
        }
    }

    printf("Plaintext: %s", text);
    return 0;
}

