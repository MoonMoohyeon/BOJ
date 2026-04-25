#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <stack>
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
    DP[5] = 1;
    DP[6] = 1;
    DP[7] = 1;
    DP[8] = 0;
    DP[9] = 1;
    DP[10] = 0;

    for (int i = 11; i <= N; i++)
    {
        if (DP[i - 1] == 0 || DP[i - 3] == 0 || DP[i - 4] == 0)
        {
            DP[i] = 1;
        }
    }

    if (DP[N] == 1)
    {
        printf("SK");
    }
    else
    {
        printf("CY");
    }

    return 0;
}