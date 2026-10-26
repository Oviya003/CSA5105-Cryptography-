
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[1000], plain[26][1000];
    double freq[26] = {
        8.12,1.49,2.71,4.32,12.02,2.30,2.03,
        5.92,7.31,0.10,0.69,3.98,2.61,6.95,
        7.68,1.82,0.11,6.02,6.28,9.10,2.88,
        1.11,2.09,0.17,2.11,0.07
    };
    double score[26] = {0}, temp;
    int shift[26], i, j, k, n = 10;
    int count[26];

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for (k=0; k<26; k++) {
        for (i=0; text[i]; i++) {
            if (isalpha((unsigned char)text[i])) {
                j = toupper(text[i])-'A';
                j = (j-k+26)%26;
                score[k] += freq[j];
            }
            plain[k][i] = text[i];
        }
        plain[k][i] = '\0';
        shift[k] = k;
    }

    for (i=0; i<26; i++) {
        for (j=i+1; j<26; j++) {
            if (score[shift[j]] > score[shift[i]]) {
                k = shift[i];
                shift[i] = shift[j];
                shift[j] = k;
            }
        }
    }

    printf("\nTop 10 possible plaintexts:\n");

    for (i=0; i<n; i++) {
        k = shift[i];
        printf("\nShift %d: ", k);

        for (j=0; text[j]; j++) {
            if (isalpha((unsigned char)text[j])) {
                int p = (toupper(text[j])-'A'-k+26)%26;
                putchar(p+'A');
            } else {
                putchar(text[j]);
            }
        }
    }

    return 0;
}

