#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <string.h>
using namespace std;

int N, S;
int arr[100000001];

int gcd(int a, int b)
{
    while (b > 0)
    {
        int tmp = a;
        a = b;
        b = tmp%b;
    }
    return a;
}

int main(void)
{
    scanf("%d %d", &N, &S);
    for(int i=0; i<N; i++)
    {
        int temp;
        scanf("%d", &temp);
        arr[i] = abs(S - temp); // 위치의 차이
    }

    // 차이 값들의 최대공약수 찾기
    int ans = arr[0];
    for(int i=1; i<N; i++)
    {
        ans = gcd(ans, arr[i]);
    }

    printf("%d\n", ans);


    return 0;
}
