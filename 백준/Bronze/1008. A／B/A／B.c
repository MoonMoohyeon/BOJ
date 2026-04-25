#include <stdio.h>
int main(void)
{
    int a;
    int b;
    double sum;
    scanf("%d", &a);
    scanf("%d", &b);
    sum = (double)a / b;
    printf("%.10f", sum);
    return 0;
}
