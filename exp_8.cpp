
#include <stdio.h>
#include <ctype.h>

int main() {
    char text[500];
    char cipher[] = "CIPHERABDFGJKLMNOQSTUVWXYZ";
    int i, p;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            p = toupper((unsigned char)text[i]) - 'A';
            text[i] = cipher[p];
        }
    }

    printf("Ciphertext: %s", text);
    return 0;
}

