#include <iostream>
using namespace std;

char graph[101][101] = { {0, } };
char mark[101] = {0, };

void DFS(int prev, int target)
{
    if(mark[target] >= 1) return;
    mark[target] = mark[prev] + 1;

    for(int i=0; i<101; i++)
    {
        if(graph[target][i] == 1)
        {
            DFS(target, i);
        }
    }
}

int main(void)
{
	int n, x, y;
    int t1, t2;
    int p;

    scanf("%d", &n);
    scanf("%d %d", &t1, &t2);
    scanf("%d", &p);

    for(int i=0; i<p; i++)
    {
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    DFS(0, t1);
    printf("%d\n", mark[t2] - 1);

    // for(int i=0; i<=p; i++)
    // {
    //     printf("%d = %d ", i, mark[i] - 1);
    // }

	return 0;
}