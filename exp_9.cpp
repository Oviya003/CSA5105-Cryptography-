
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char key[26], text[500];
    int pos[26][2], i, r, c;
    int r1, c1, r2, c2;

    printf("Enter 25-letter key square: ");
    scanf("%25s", key);

    printf("Enter even-length ciphertext: ");
    scanf("%499s", text);

    for (i = 0; i < 25; i++) {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';
        pos[ch-'A'][0] = i / 5;
        pos[ch-'A'][1] = i % 5;
    }

    for (i = 0; text[i] && text[i+1]; i += 2) {
        r1 = pos[toupper(text[i])-'A'][0];
        c1 = pos[toupper(text[i])-'A'][1];
        r2 = pos[toupper(text[i+1])-'A'][0];
        c2 = pos[toupper(text[i+1])-'A'][1];

        if (r1 == r2) {
            c1 = (c1 + 4) % 5;
            c2 = (c2 + 4) % 5;
        } else if (c1 == c2) {
            r1 = (r1 + 4) % 5;
            r2 = (r2 + 4) % 5;
        } else {
            c = c1; c1 = c2; c2 = c;
        }

        putchar(key[r1*5+c1]);
        putchar(key[r2*5+c2]);
    }

    printf("\n");
    return 0;
}

