#include <iostream>
#include <math.h>
using namespace std;

int cnt = 0;
int n;
int board[16] = {0, };

bool check(int col)
{
    for (int i = 1; i < col; i++)
    {
        if (board[i] == board[col] || (col - i) == abs(board[i] - board[col]))
            return false;
    }

    return true;
}

void nqueen(int col)
{
    if (col > n)
    {
        cnt++;
        return;
    }

    for (int row = 1; row <= n; row++)
    {
        board[col] = row;
        if (check(col))
        {
            nqueen(col + 1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    nqueen(1);
    printf("%d", cnt);
    return 0;
}
