#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    int m;
    int card[101] = {
        0,
    };
    scanf("%d %d", &num, &m);

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &card[i]);
    }

    int sum = 0;
    int max = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            for (int k = j + 1; k < num; k++)
            {
                sum = card[i] + card[j] + card[k];
                if (sum > m)
                    continue;
                if (sum > max)
                    max = sum;
            }
        }
    }

    printf("%d", max);
}
