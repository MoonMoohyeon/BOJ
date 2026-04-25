#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    char d;
    char str[6];
    int count = 0;
    scanf("%d %c", &n, &d);
    while (n != 0)
    {
        sprintf(str, "%d", n);
        for (int i = 0; i < 6; i++)
        {
            if (str[i] == d)
            {
                count++;
            }
        }
        n--;
    }

    printf("%d", count);
}
