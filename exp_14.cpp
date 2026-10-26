
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[] = "send more money";
    int key[] = {9,0,1,7,23,15,21,14,11,11,2,8,9};
    int i, j=0, p, c;

    printf("Ciphertext: ");

    for (i=0; text[i]; i++) {
        if (isalpha((unsigned char)text[i])) {
            p = tolower(text[i])-'a';
            c = (p + key[j])%26;
            printf("%c", c+'A');
            j++;
        }
    }

    printf("\n");
    return 0;
}

