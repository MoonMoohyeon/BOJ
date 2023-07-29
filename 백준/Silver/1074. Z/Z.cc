#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
#include <limits.h>
#include <string.h>
using namespace std;

int N;
int r, c;
int res = 0;

void z(int N, int row, int col)
{
    if (c == row && r == col) {
        printf("%d\n", res);
        return;
    }
    else if (c < row + N && r < col + N && c >= row && r >= col) {
        z(N / 2, row, col);
        z(N / 2, row + N / 2, col);
        z(N / 2, row, col + N / 2);
        z(N / 2, row + N / 2, col + N / 2);
    }
    else {
        res += N * N;
    }
}

int main(void)
{
    scanf("%d %d %d", &N, &r, &c);
    z(pow(2, N), 0, 0);

    return 0;
}
