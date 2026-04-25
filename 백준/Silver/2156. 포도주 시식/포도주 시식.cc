#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    int input[10001];
    int DT[10001];
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf(" %d", &input[i]);
    }

    DT[0] = 0;
    DT[1] = input[1];
    DT[2] = input[1] + input[2];
    // DT[3] = max(DT[2], input[2] + input[3]);
    // DT[4] = max(DT[3], DT[1] + input[3] + input[4]);
    // DT[5] = max(DT[4], DT[2] + input[4] + input[5]);
    // DT[6] = max(DT[5], DT[3] + input[5] + input[6]);

    for (int i = 3; i <= N; i++)
    {
        DT[i] = max(DT[i - 2] + input[i], DT[i - 3] + input[i - 1] + input[i]);
        DT[i] = max(DT[i], DT[i - 1]);
    }

    printf("%d", DT[N]);

    return 0;
}