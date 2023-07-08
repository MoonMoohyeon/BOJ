#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int parent[200001];
pair<long, pair<int, int>> edge[200001];

int find(int x)
{
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void Union(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;

}

int isUnion(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return 1;
    else return 0;
}

int main(void)
{
    int V, E;
    int a, b, c;
    while (true)
    {
        long long sum = 0;
        int cnt = 0;
        scanf("%d %d", &V, &E);
        if (V == 0 && E == 0) break;

        for (int i = 0; i <= V; i++)
        {
            parent[i] = i;
            edge[i] = { 0,{0,0} };
        }

        for (int i = 0; i < E; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[i] = { c,{a,b} };
            sum += c;
        }

        sort(edge, edge + E);
        for (int i = 0; i < E; i++)
        {
            if (!isUnion(edge[i].second.first, edge[i].second.second)) {
                Union(edge[i].second.first, edge[i].second.second);
                sum -= edge[i].first;
                cnt++;
            }
            if (cnt == V - 1) break;
        }

        printf("%lld\n", sum);
    }

    return 0;
}