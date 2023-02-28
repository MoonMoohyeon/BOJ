#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(void)
{
    long long int n1, n2;
    scanf("%lld %lld", &n1, &n2);
    long long int a = n1;
    long long int b = n2;
    if (n1 < n2)
    {
        while (n2 > 0)
        {
            long long int tmp = n1 % n2;
            n1 = n2;
            n2 = tmp;
        }
        printf("%lld\n", (a / n1) * (b / n1) * n1);
    }
    else
    {
        while (n1 > 0)
        {
            long long int tmp = n2 % n1;
            n2 = n1;
            n1 = tmp;
        }
        printf("%lld\n", (a / n2) * (b / n2) * n2);
    }

    return 0;
}