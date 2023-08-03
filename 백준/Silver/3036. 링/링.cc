#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <string.h>
using namespace std;

int N;
int ring[101];

int gcd(int a, int b)
{
    while (b > 0)
    {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &ring[i]);
    }

    for (int i = 1; i < N; i++)
    {
        int ans = gcd(ring[0], ring[i]);
        printf("%d/%d\n", ring[0]/ans, ring[i]/ans);
    }

    return 0;
}
