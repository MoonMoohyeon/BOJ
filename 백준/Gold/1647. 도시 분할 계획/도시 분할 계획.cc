#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;

struct edge {
    int a, b, c;
    bool operator<(const edge& other) const {
        return c < other.c;
    }
};

vector<edge> edges;
int parent[100001];
int ran[100001];

void init() {
    for (int i = 0; i < 100001; ++i) {
        parent[i] = i;
        ran[i] = 0;
    }
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void uni(int a, int b) {
    int ra = find(a);
    int rb = find(b);

    if (ra != rb) {
        if (ran[ra] < ran[rb]) swap(ra, rb);
        parent[rb] = ra;

        if (ran[ra] == ran[rb]) ran[ra]++;
    }
}

int is_uni(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra == rb) return 1;
    return 0;
}

int main(int argc, char* argv[]) {
    scanf("%d %d", &N, &M);
    init();

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back({ a,b,c });
    }

    sort(edges.begin(), edges.end());

    int edge_cnt = 0;
    int sum = 0;
    int max_edge = 0;

    for (int i = 0; i < M; ++i) {
        int a = edges[i].a;
        int b = edges[i].b;
        int c = edges[i].c;
        if (!is_uni(a, b)) {
            uni(a, b);
            sum += c;
            if (c > max_edge) max_edge = c;
            edge_cnt++;
        }

        if (edge_cnt == N - 1) break;
    }
    
    printf("%d", sum - max_edge);

    return 0;
}
