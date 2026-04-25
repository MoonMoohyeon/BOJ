#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(void)
{
    int T;
    scanf("%d", &T);
    int n1, n2;
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &n1, &n2);
        int a = n1;
        int b = n2;
        if (n1 < n2)
        {
            while (n2 > 0)
            {
                int tmp = n1 % n2;
                n1 = n2;
                n2 = tmp;
            }
            printf("%d\n", (a/n1) * (b/n1) * n1);
        }
        else
        {
            while (n1 > 0)
            {
                int tmp = n2 % n1;
                n2 = n1;
                n1 = tmp;
            }
            printf("%d\n", (a/n2) * (b/n2) * n2);
        }
    }

    return 0;
}