#include <stdio.h>
#include <stdlib.h>
using namespace std;

int DP[1001];

int main(void)
{
    int N;
    scanf("%d", &N);
    DP[0] = 0;
    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 0;
    DP[4] = 1;
    DP[5] = 0;
    DP[6] = 1;
    DP[7] = 0;
    DP[8] = 1;

    for (int i = 9; i < 1001; i++)
    {
        if (DP[i - 1] == 0 || DP[i - 3] == 0)
            DP[i] = 1;
        if (DP[i - 1] == 1 || DP[i - 3] == 1)
            DP[i] = 0;
    }

    if (DP[N] != 0)
        printf("CY");
    else
        printf("SK");

    return 0;
}
