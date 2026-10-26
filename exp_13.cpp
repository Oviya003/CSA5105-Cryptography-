
#include <stdio.h>

int main() {
    int p, q, r, s, a, b, c, d;
    int det, inv = -1, i;
    int x, y, z, w;

    printf("Enter plaintext matrix values row-wise: ");
    scanf("%d%d%d%d", &p,&q,&r,&s);

    printf("Enter corresponding ciphertext matrix values: ");
    scanf("%d%d%d%d", &a,&b,&c,&d);

    det = (p*s - q*r + 2600) % 26;

    for (i=1; i<26; i++)
        if ((det*i)%26 == 1) {
            inv = i;
            break;
        }

    if (inv == -1) {
        printf("Plaintext matrix is not invertible.\n");
        return 0;
    }

    x = ((a*s-b*r)*inv % 26 + 2600)%26;
    y = ((b*p-a*q)*inv % 26 + 2600)%26;
    z = ((c*s-d*r)*inv % 26 + 2600)%26;
    w = ((d*p-c*q)*inv % 26 + 2600)%26;

    printf("Recovered key matrix:\n");
    printf("%d %d\n%d %d\n", x,y,z,w);

    return 0;
}

