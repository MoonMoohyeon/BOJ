#include <stdio.h>
#include <stdlib.h>

int DT[1000][10];

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 10; i++)
        DT[0][i] = 1;

    for (int i = 1; i < n; i++)
    {
        int temp = 0;
        for (int j = 9; j >= 0; j--)
        {
            temp += DT[i - 1][j];
            DT[i][j] = temp % 10007;
            // printf("%d ", temp);
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += (DT[n - 1][i] % 10007);
    }
    printf("%d", sum % 10007);

    return 0;
}
