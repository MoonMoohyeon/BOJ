#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int DP[1000001];

int main(void)
{
    int N;
    scanf("%d", &N);
    DP[0] = 0;
    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 1;
    DP[4] = 2;
    DP[5] = 3;
    
    for (int i = 6; i <= N; i++)
    {
        if (i % 3 == 0 && i % 2 == 0)
        {
            DP[i] = min({ DP[i / 3], DP[i / 2], DP[i - 1] }) + 1;
        }
        else if (i % 3 == 0)
        {
            DP[i] = min({DP[i / 3], DP[i - 1]}) + 1;
        }
        else if (i % 2 == 0)
        {
            DP[i] = min(DP[i / 2], DP[i - 1]) + 1;
        }
        else
        {
            DP[i] = DP[i - 1] + 1;
        }
    }

    printf("%d", DP[N]);

    return 0;
}
