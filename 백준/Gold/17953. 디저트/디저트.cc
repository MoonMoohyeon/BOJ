#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <string.h>
using namespace std;

int N, M;
int des[11][100001];
int DP[100001][11] = { 0, };

int main(void)
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &des[i][j]); // i번째 날에 j번 디저트를 먹었을 때의 만족감.
        }
    }

    // DP[i][j] = i번째 날의 j번째 디저트를 먹었을 때의 최대 만족감.

    // DP[1][1] = des[1][1];
    // DP[1][2] = des[2][1];
    // DP[2][1] = max(DP[1][1] + des[1][2] / 2, DP[1][2] + des[1][2]);
    // DP[2][2] = max(DP[1][1] + des[2][2], DP[1][2] + des[2][2] / 2);
    // DP[3][1] = max(DP[2][1] + des[1][3] / 2, DP[2][2] + des[1][3]);
    // DP[3][2] = max(DP[2][1] + des[2][3], DP[2][2] + des[2][3] / 2);

    for (int i = 1; i <= M; i++)
    {
        DP[1][i] = des[i][1];
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            for (int k = 1; k <= M; k++)
            {
                if (j == k)
                {
                    DP[i][k] = max(DP[i][k], DP[i - 1][j] + des[k][i] / 2);
                    continue;
                }
                DP[i][k] = max(DP[i][k], DP[i - 1][j] + des[k][i]);
            }
        }
    }

    // for(int i=1; i<=N; i++)
    // {
    //     for(int j=1; j<=M; j++)
    //     {
    //         printf("%d ", DP[i][j]); // i번째 날에 j번 디저트를 먹었을 때의 만족감.
    //     }
    //     printf("\n");
    // }

    int ans = 0;
    for (int i = 1; i <= M; i++)
    {
        if (DP[N][i] > ans) ans = DP[N][i];
    }

    printf("%d\n", ans);
    return 0;
}
