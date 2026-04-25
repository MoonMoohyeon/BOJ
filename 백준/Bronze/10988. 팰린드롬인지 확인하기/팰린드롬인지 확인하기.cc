#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[100];
    scanf("%s", str);
    int len = strlen(str);
    int flag = 1;

    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            flag = 0;
        }
    }

    printf("%d", flag);
}
