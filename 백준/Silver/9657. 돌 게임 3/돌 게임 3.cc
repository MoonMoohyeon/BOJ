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

    DP[1] = 1;
    DP[2] = 0;
    DP[3] = 1;
    DP[4] = 1;

    for (int i = 5; i <= N; i++)
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