#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
    int N;
    char str[101];
    int cnt = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int alpha[200] = { 0, };
        scanf("%s", str);
        alpha[(int)str[0]] = 1;
        for (int j = 1; j < strlen(str); j++)
        {
            if (alpha[(int)str[j]] == 1 && str[j] != str[j - 1])
            {
                cnt++;
                break;
            }
            else
            {
                alpha[(int)str[j]] = 1;
            }
        }
    }

    printf("%d\n", N - cnt);

    return 0;
}
