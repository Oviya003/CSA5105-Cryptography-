
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char sq[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};

int main() {
    char text[500], a, b;
    int i, j, r1, c1, r2, c2, n = 0;
    char p[500];

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i]; i++)
        if (isalpha((unsigned char)text[i])) {
            a = toupper(text[i]);
            if (a == 'J') a = 'I';
            p[n++] = a;
        }

    if (n % 2) p[n++] = 'X';

    for (i = 0; i < n; i += 2) {
        a = p[i]; b = p[i+1];

        for (r1=0; r1<5; r1++)
            for (c1=0; c1<5; c1++)
                if (sq[r1][c1] == a) goto found1;
        found1:

        for (r2=0; r2<5; r2++)
            for (c2=0; c2<5; c2++)
                if (sq[r2][c2] == b) goto found2;
        found2:

        if (r1 == r2) {
            a = sq[r1][(c1+1)%5];
            b = sq[r2][(c2+1)%5];
        } else if (c1 == c2) {
            a = sq[(r1+1)%5][c1];
            b = sq[(r2+1)%5][c2];
        } else {
            a = sq[r1][c2];
            b = sq[r2][c1];
        }

        printf("%c%c", a, b);
    }

    printf("\n");
    return 0;
}

