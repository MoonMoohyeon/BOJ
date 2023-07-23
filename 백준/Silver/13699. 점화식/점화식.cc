#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#define ull unsigned long long
using namespace std;

ull t[36];

int main(void)
{
    int n;
    scanf("%d", &n);

    t[0] = 1;
    //t[1] = t[0] * t[0];
    //t[2] = t[0] * t[1] + t[1] * t[0];
    //t[3] = t[0] * t[2] + t[1] * t[1] + t[2] * t[0];
    //t[4] = t[0] * t[3] + t[1] * t[2] + t[2] * t[1] + t[3] * t[0];
    //t[5] = t[0] * t[4] + t[1] * t[3] + t[2] * t[2] + t[3] * t[1] + t[4] * t[0];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            t[i] += t[i - j - 1] * t[j];
        }
    }

    /*for (int i = 1; i <= n; i++)
    {
        printf("%lld ", t[i]);
    }*/

    printf("%lld\n", t[n]);

    return 0;
}
