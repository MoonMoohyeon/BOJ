#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main(void)
{
    int h, m, n;
    scanf("%d %d", &h, &m);
    scanf("%d", &n);
    h += n / 60;
    m += n % 60;
    if (m >= 60)
    {
        h += 1;
        m -= 60;
    }
    if (h >= 24) h -= 24;
    printf("%d %d", h, m);

    return 0;
}