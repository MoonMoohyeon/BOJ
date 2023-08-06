#include <stdio.h>

int main()
{
    int N, K;
    int ans = 1;
    int div = 1;
    scanf("%d %d", &N, &K);
    
    for(int i=0; i<K; i++)
    {
        ans *= (N - i);
    }

    for(int i=0; i<K; i++)
    {
        div *= (K - i);
    }

    // printf("%d %d\n", ans, div);
    printf("%d\n", ans / div);

    return 0;
}