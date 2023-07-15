#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <string.h>
using namespace std;

int N, K, W, V;

int DP[101][100001] = { {0, } };
int weights[101] = { 0, };
int values[101] = { 0, };

int main(void)
{
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d", &W, &V);
        weights[i] = W;
        values[i] = V;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int w = 1; w <= K; w++)
        {
            if (weights[i] > w) // 새 물건을 못넣으면 아예 고려하지 않음
            {
                DP[i][w] = DP[i - 1][w];
            }
            else // 물건을 안넣는 경우와 넣는 경우 중 큰 값
            {
                int no = DP[i - 1][w]; // 물건을 안넣는 경우
                int yes = DP[i - 1][w - weights[i]] + values[i]; // 새 물건을 넣는 경우
                DP[i][w] = max(no, yes); // 테이블에qee67680 저장되는 값을 현재까지의 최적값임을 보장
            }
        }
    }

    /*for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            printf("%d ", DP[i][j]);
        }
        printf("\n");
    }*/

    printf("%d\n", DP[N][K]);

    return 0;
}
