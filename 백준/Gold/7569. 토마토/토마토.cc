#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int M, N, H;

int main(void)
{
    scanf("%d %d %d", &M, &N, &H);
    int*** graph;
    graph = (int***)malloc(sizeof(int**) * H);
    for (int i = 0; i < H; i++)
    {
        graph[i] = (int**)malloc(sizeof(int*) * N);
        for (int j = 0; j < N; j++)
        {
            graph[i][j] = (int*)malloc(sizeof(int) * M);
        }
    }

    int temp;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                scanf("%d", &temp);
                graph[i][j][k] = temp;
            }
        }
    }


    queue<pair<pair<int, int>, int>> q;
    queue<int> h;
    queue<int> n;
    queue<int> m;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (graph[i][j][k] == 1)
                {
                    q.push({ {j,k},i });
                    h.push(i);
                    n.push(j);
                    m.push(k);
                }
            }
        }
    }

    while (1)
    {
        if (q.empty())
            break;
        
        pair<pair<int, int>, int> out = q.front();
        pair<pair<int, int>, int> up, down, left, right, upper, lower;
        int h = out.second;
        int n = out.first.first;
        int m = out.first.second;
        q.pop();

        int suf = 0, sdf = 0;
        int uf = 0, df = 0, lf = 0, rf = 0;
        int sui=0, sum=0, sun=0;
        int sdi=0, sdm=0, sdn=0;
        int ui=0, um=0, un=0;
        int di=0, dm=0, dn=0;
        int li=0, lm=0, ln=0;
        int ri=0, rm=0, rn=0;
        //printf("flag = %d %d %d %d %d %d\n", suf, sdf, uf, df, lf, rf);

        if (h + 1 >= 0 && h + 1 < H && n >= 0 && n < N && m >= 0 && m < M)
        {
            if (graph[h + 1][n][m] == 0)
            {
                graph[h + 1][n][m] = graph[h][n][m] + 1;
                suf = 1;
                upper = {{ n,m }, h+1};
            }
        }
        if (h - 1 >= 0 && h - 1 < H && n >= 0 && n < N && m >= 0 && m < M)
        {
            if (graph[h - 1][n][m] == 0)
            {
                graph[h - 1][n][m] = graph[h][n][m] + 1;
                sdf = 1;
                lower = { { n,m }, h -1};
            }
        }
        if (h >= 0 && h < H && n + 1 >= 0 && n + 1 < N && m >= 0 && m < M)
        {
            if (graph[h][n + 1][m] == 0)
            {
                graph[h][n + 1][m] = graph[h][n][m] + 1;
                uf = 1;
                up = { { n+1,m }, h };
            }
        }
        if (h >= 0 && h < H && n - 1 >= 0 && n - 1 < N && m >= 0 && m < M)
        {
            if (graph[h][n - 1][m] == 0)
            {
                graph[h][n - 1][m] = graph[h][n][m] + 1;
                df = 1;
                down = { { n-1,m }, h };
            }
        }
        if (h >= 0 && h < H && n >= 0 && n < N && m + 1 >= 0 && m + 1 < M)
        {
            if (graph[h][n][m + 1] == 0)
            {
                graph[h][n][m + 1] = graph[h][n][m] + 1;
                rf = 1;
                right = { { n,m+1 }, h };
            }
        }
        if (h >= 0 && h < H && n >= 0 && n < N && m - 1 >= 0 && m - 1 < M)
        {
            if (graph[h][n][m - 1] == 0)
            {
                graph[h][n][m - 1] = graph[h][n][m] + 1;
                lf = 1;
                left = { { n,m-1 }, h };
            }
        }
        //printf("flag = %d %d %d %d %d %d\n", suf, sdf, uf, df, lf, rf);
        if (suf == 1) q.push(upper);
        if (sdf == 1) q.push(lower);
        if (uf == 1) q.push(up);
        if (df == 1) q.push(down);
        if (lf == 1) q.push(left);
        if (rf == 1) q.push(right);

        /*printf("\n");
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < M; k++)
                {
                    printf("%d ", graph[i][j][k]);
                }
                printf("\n");
            }
            printf("\n");
        }*/
    }

    int max = -1;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (graph[i][j][k] > max && max != 0)
                    max = graph[i][j][k];
                if (graph[i][j][k] == 0) max = 0;
            }
        }
    }

    printf("%d", --max);

    return 0;
}
