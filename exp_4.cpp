#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char p[100], key[100], c[100];
    int i, k;

    printf("Enter plaintext: ");
    scanf("%s", p);

    printf("Enter key: ");
    scanf("%s", key);

    for(i = 0, k = 0; p[i] != '\0'; i++, k++)
    {
        if(k == strlen(key))
            k = 0;

        c[i] = ((toupper(p[i]) - 'A') +
                (toupper(key[k]) - 'A')) % 26 + 'A';
    }

    c[i] = '\0';

    printf("Ciphertext: %s", c);

    return 0;
}
