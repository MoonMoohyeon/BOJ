#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int maze[1001][1001];
int DP[1001][1001];

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }

    memset(DP, 0, sizeof(DP));
    DP[1][1] = maze[1][1];
    DP[1][2] = DP[1][1] + maze[1][2];
    DP[2][1] = DP[1][1] + maze[2][1];
    DP[2][2] = DP[1][1] + maze[2][2];

    // DP[3][3] = max({DP[2][2], DP[2][3], DP[3][2]}) + maze[3][3];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            DP[i][j] = max({DP[i - 1][j - 1], DP[i - 1][j], DP[i][j - 1]}) + maze[i][j];
        }
    }

    // printf("DP = \n");
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= M; j++)
    //     {
    //         printf("%d ", DP[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d", DP[N][M]);

    return 0;
}