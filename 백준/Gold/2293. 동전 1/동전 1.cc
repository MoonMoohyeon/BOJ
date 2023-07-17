#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <string.h>
using namespace std;

int n, k;

int DP[10001] = {0, };
int values[101] = {0, }; 

/*
    1차원 테이블 갱신 = 
    (n원짜리 동전을 사용하지 않고) v-n원을 만드는 경우의 수 + v원을 만드는 경우의 수
*/

int main(void)
{
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++)
    {
            scanf("%d", &values[i]);
    }

    DP[0] = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=values[i]; j<=k; j++)
        {
            DP[j] = DP[j] + DP[j - values[i]];
        }
    }

    printf("%d\n", DP[k]);
    return 0;
}
