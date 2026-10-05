#include <stdio.h>
#include <ctype.h>

int main()
{
    char p[100];
    int k;

    printf("Enter plaintext: ");
    scanf("%s", p);

    printf("Enter key: ");
    scanf("%d", &k);

    for(int i = 0; p[i]; i++)
        p[i] = (toupper(p[i]) - 'A' + k) % 26 + 'A';

    printf("Ciphertext: %s", p);

    return 0;
}
