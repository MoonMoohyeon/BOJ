#include <iostream>
using namespace std;


int main(void)
{
    int x1, x2, x3, y1, y2, y3;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);

    int res = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
    if (res > 0) printf("1");
    else if (res == 0) printf("0");
    else printf("-1");
    
    return 0;
}
