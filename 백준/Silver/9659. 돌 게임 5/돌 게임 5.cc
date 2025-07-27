#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(void)
{
    char N[14];
    scanf("%s", N);
    int p = strlen(N);
    p--;
    if (N[p] == '0' || N[p] == '2' || N[p] == '4' || N[p] == '6' || N[p] == '8')
    {
        printf("CY");
    }
    else
    {
        printf("SK");
    }

    return 0;
}
