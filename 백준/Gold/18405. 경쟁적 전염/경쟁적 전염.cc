#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int graph[201][201] = { {0, } };
struct cmp {
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) // 가중치, a 노드, b 노드
    {
        if (a.first > b.first)
            return true;
        else
            return false;
    }
};

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
queue<pair<int, pair<int, int>>> q;
int N, K;

int main(void)
{
    scanf("%d %d", &N, &K);
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            scanf("%d", &graph[i][j]);
            int temp = graph[i][j];
            if(temp != 0)
            {
                pq.push(make_pair(temp, make_pair(i, j)));
                // printf("\npush %d %d %d", temp, i, j);
            }
        }
    }

    int X, Y, S;
    int cnt = 0;
    scanf("%d %d %d", &S, &X, &Y);
    while(cnt != S)
    {
        while(!pq.empty())
        {
            auto next = pq.top();
            pq.pop();
            int x, y, v;
            v = next.first;
            x = next.second.first;
            y = next.second.second;
            // printf("next = %d %d %d\n", v, x, y);
            if(x + 1 <= N && graph[x + 1][y] == 0)
            {
                graph[x+1][y] = v;
                q.push(make_pair(v, make_pair(x+1, y)));
            }
            if(x - 1 > 0 && graph[x - 1][y] == 0)
            {
                graph[x-1][y] = v;
                q.push(make_pair(v, make_pair(x-1, y)));
            }
            if(y + 1 <= N && graph[x][y + 1] == 0)
            {
                graph[x][y+1] = v;
                q.push(make_pair(v, make_pair(x, y+1)));
            }
            if(y-1 > 0 && graph[x][y - 1] == 0)
            {
                graph[x][y-1] = v;
                q.push(make_pair(v, make_pair(x, y-1)));
            }
        }
        while(!q.empty())
        {
            auto pv = q.front();
            q.pop();
            // printf("q = %d %d %d\n", pv.first, pv.second.first, pv.second.second);
            pq.push(make_pair(pv.first, make_pair(pv.second.first, pv.second.second)));
        }
        cnt++;

        // printf("\n cnt = %d\n", cnt);
        // for(int i=1; i<=N; i++)
        // {
        //     for(int j=1; j<=N; j++)
        //     {
        //         printf("%d ", graph[i][j]);
        //     }
        //     printf("\n");
        // }
    }

    // printf("\n");
    printf("%d\n", graph[X][Y]);


	return 0;
}