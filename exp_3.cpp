#include <stdio.h>
#include <string.h>
#include <ctype.h>

char key[5][5];

void create(char s[])
{
    char used[26] = {0};
    int r = 0, c = 0;

    for (int i = 0; s[i]; i++) {
        char ch = toupper(s[i]);
        if (ch == 'J') ch = 'I';

        if (!used[ch-'A']) {
            key[r][c++] = ch;
            used[ch-'A'] = 1;
            if (c == 5) c = 0, r++;
        }
    }

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue;
        if (!used[ch-'A']) {
            key[r][c++] = ch;
            used[ch-'A'] = 1;
            if (c == 5) c = 0, r++;
        }
    }
}

void encrypt(char p[])
{
    for (int i = 0; p[i]; i += 2) {
        char x = p[i], y = p[i+1];
        int r1,c1,r2,c2;

        for (int r=0;r<5;r++)
            for (int c=0;c<5;c++) {
                if(key[r][c]==x) r1=r,c1=c;
                if(key[r][c]==y) r2=r,c2=c;
            }

        if(r1==r2) {
            p[i]=key[r1][(c1+1)%5];
            p[i+1]=key[r2][(c2+1)%5];
        }
        else if(c1==c2) {
            p[i]=key[(r1+1)%5][c1];
            p[i+1]=key[(r2+1)%5][c2];
        }
        else {
            p[i]=key[r1][c2];
            p[i+1]=key[r2][c1];
        }
    }
}

int main()
{
    char k[20], p[100];

    printf("Key: ");
    scanf("%s",k);

    printf("Plaintext: ");
    scanf("%s",p);

    for(int i=0;p[i];i++)
        p[i]=toupper(p[i]);

    if(strlen(p)%2) strcat(p,"X");

    create(k);
    encrypt(p);

    printf("Ciphertext: %s",p);

    return 0;
}
