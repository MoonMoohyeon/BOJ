#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int ran[500001];
int parent[500001];


int find(int x) {
    if (parent[x] == x) {
        return x;
    }

    return parent[x] = find(parent[x]);
}

int isunion(int a, int b) {
    if (find(a) == find(b)) {
        return 1;
    }
    
    return 0;
}

void uni(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {
        if (ran[rootA] < ran[rootB]) {
            parent[rootA] = rootB;
        }
        else {
            parent[rootB] = rootA;
            if (ran[rootA] == ran[rootB]) {
                ran[rootA]++;
            }
        }
    }
}

int main(void)
{
    cin >> N >> M;

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
        ran[i] = 0;
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cnt++;
        if (isunion(a, b)) {
            cout << cnt << endl;
            return 0;
        }
        uni(a, b);
    }
    cout << "0" << endl;


    return 0;
}