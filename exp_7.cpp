
#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    char key[27];
    int i;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter 26-letter decryption key: ");
    scanf("%26s", key);

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = key[text[i] - 'A'];
        else if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = tolower(key[text[i] - 'a']);
    }

    printf("Plaintext: %s", text);
    return 0;
}

