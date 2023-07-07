#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct triple {
    long long a;
    long long b;
    long long c;
};

bool cmp(triple a, triple b)
{
    if (a.c > b.c) return false;
    else return true;
}

int parent[100001];
vector<struct triple> vec;

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
    scanf("%d %d", &V, &E);
    long long sum = 0;
    int cnt = 0;
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < E; i++)
    {
        struct triple t;
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);
        t.a = a;
        t.b = b;
        t.c = c;
        vec.push_back(t);
        sum += t.c;
    }

    sort(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < E; i++)
    {
        if (!isUnion(vec[i].a, vec[i].b)) {
            Union(vec[i].a, vec[i].b);
            sum -= vec[i].c;
            cnt++;
        }
    }

    if (cnt == V - 1)
        printf("%lld\n", sum);
    else 
        printf("-1\n");

    return 0;
}