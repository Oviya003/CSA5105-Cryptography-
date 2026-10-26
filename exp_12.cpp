
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[200], enc[200];
    int p, q, c1, c2, i, n = 0;
    int inv[2][2] = {{5,12},{15,25}};

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (i=0; text[i]; i++)
        if (isalpha((unsigned char)text[i]))
            enc[n++] = toupper(text[i]);

    if (n % 2) enc[n++] = 'X';
    enc[n] = '\0';

    printf("Ciphertext: ");
    for (i=0; i<n; i+=2) {
        p = enc[i]-'A';
        q = enc[i+1]-'A';
        c1 = (9*p + 4*q)%26;
        c2 = (5*p + 7*q)%26;
        printf("%c%c", c1+'A', c2+'A');
    }

    printf("\n");
    return 0;
}

