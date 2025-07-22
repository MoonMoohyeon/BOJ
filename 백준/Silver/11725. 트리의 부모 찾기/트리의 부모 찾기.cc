#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

int N, M, K;
vector<int> graph[100001];
int mark[100001] = { 0, };

void DFS(int s, int p) {
    if (mark[s]) return;
    mark[s] = p;
    for (auto i = graph[s].begin(); i != graph[s].end(); i++) {
        DFS(*i, s);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int i, j;
    for (int k = 1; k < N; k++) {
        cin >> i >> j;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }

    DFS(1, -1);
    for (int i = 2; i <= N; i++) cout << mark[i] << "\n";

    return 0;
}
