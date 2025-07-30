#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    }
    else if (n == 1) {
        printf("1");
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

pair<int,int> DP[41];

int main(void)
{
    int T, num;
    scanf("%d", &T);

    DP[0] = { 0,1 };
    DP[1] = { 1,0 };
    DP[2] = { 1,1 };
    DP[3] = { 2,1 };

    for (int i = 4; i < 41; i++)
    {
        DP[i] = make_pair(DP[i - 2].first + DP[i - 1].first, DP[i - 2].second + DP[i - 1].second);
    }

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &num);
        printf("%d %d\n", DP[num].second, DP[num].first);
    }

    return 0;
}