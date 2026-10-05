#include <stdio.h>
#include <ctype.h>

int main()
{
    char p[100], key[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";

    printf("Enter plaintext: ");
    scanf("%s", p);

    for(int i = 0; p[i]; i++)
        p[i] = key[toupper(p[i]) - 'A'];

    printf("Ciphertext: %s", p);

    return 0;
}
