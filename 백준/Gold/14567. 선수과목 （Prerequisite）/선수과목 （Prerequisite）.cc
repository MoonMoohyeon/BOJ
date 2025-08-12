#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> graph[1001];
int indgree[1001] = { 0, };
int mark[1001] = { 0, };

void topo(int start) {
    for (auto i = graph[start].begin(); i != graph[start].end(); i++) {
        if (mark[*i] < mark[start] + 1) {
            mark[*i] = mark[start] + 1;
            topo(*i);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indgree[b]++;
    }

    for (int i = 1; i <= N; i++) {
        if (indgree[i] == 0 && mark[i] == 0) {
            mark[i] = 1;
            topo(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << mark[i] << " ";
    }

    return 0;
}