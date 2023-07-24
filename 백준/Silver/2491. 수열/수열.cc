#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int main(void)
{
    int N;
    int num[100001];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }

    int inc = 1;
    int dec = 1;
    int incres = 1;
    int decres = 1;
    for (int i = 0; i < N - 1; i++)
    {
        if (num[i] <= num[i + 1]) inc++;
        else inc = 1;
        if (num[i + 1] <= num[i]) dec++;
        else dec = 1;

        if (inc > incres) incres = inc;
        if (dec > decres) decres = dec;

        //printf("%d %d\n", incres, decres);
    }

    printf("%d", max(incres, decres));

    return 0;
}
