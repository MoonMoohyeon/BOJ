#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int N;
int parent[1000001];
int ran[1000001];

void init() {
    for (int i = 0; i < 1000001; ++i) {
        ran[i] = 1;
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void uni(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra != rb) {
        if (ran[ra] < ran[rb]) {
            swap(ra, rb);
        }

        parent[rb] = ra;
        ran[ra] += ran[rb];
    }
}


int main(int argc, char* argv[]) {
    scanf("%d", &N);
    init();
    for (int t = 0; t < N; ++t) {
        char cmd;
        scanf(" %c", &cmd);
        if (cmd == 'I') {
            int a, b;
            scanf("%d %d", &a, &b);
            uni(a, b);
        }
        else {
            int c;
            scanf("%d", &c);
            printf("%d\n", ran[find(c)]);
        }
    }

    return 0;
}