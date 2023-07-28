#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <string.h>
using namespace std;

int N;
int paper[129][129];
int blue = 0;
int white = 0;

void frag(int N, int row, int col)
{
    int flag = paper[row][col];
    //printf("*** %d %d %d\n", N, row, col);
    for (int i = row; i < row+N; i++)
    {
        for (int j = col; j < col+N; j++)
        {
            if (flag != paper[i][j])
            {
                frag(N / 2, row, col);
                frag(N / 2, row, col + N / 2);
                frag(N / 2, row + N / 2, col);
                frag(N / 2, row + N / 2, col + N / 2);

                return;
            }
        }
    }

    if (flag)
        white += 1;
    else
        blue += 1;
}

int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &paper[i][j]);
        }
    }

    frag(N, 0, 0);

    printf("%d\n%d\n", blue, white);

    return 0;
}
