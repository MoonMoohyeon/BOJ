#include <stdio.h>
#include <stdlib.h>

long P[101];

int main(void)
{
    int N, T;
    scanf("%d", &T);
    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2; // 2 + 3
    P[5] = 2; // 4
    P[6] = 3; // 5 + 3
    P[7] = 4; // 6 + 1
    P[8] = 5; // 7 + 2
    P[9] = 7; // 8 + 4
    // P[10] = 9;  // 9 + 5
    // P[11] = 12; // 10 + 6
    // P[12] = 16; // 11 + 7
    // P[13] = 21; // 12 + 8
    // P[14] = 28; // 13 + 9

    for (int i = 10; i < 101; i++)
    {
        P[i] = P[i - 1] + P[i - 5];
    }

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        printf("%ld\n", P[N]);
    }

    return 0;
}
