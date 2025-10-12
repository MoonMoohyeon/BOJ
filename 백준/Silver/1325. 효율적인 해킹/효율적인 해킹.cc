#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector<int> graph[10001];
int cnt[10001] = { 0, };
bool mark[10001] = { false, };

int BFS(int start_node) {
    queue<int> q;
    q.push(start_node);
    mark[start_node] = true;
    int count = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (!mark[next]) {
                mark[next] = true;
                q.push(next);
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    int max_cnt = 0;
    for (int i = 1; i <= N; i++) {
        memset(mark, false, sizeof(mark));
        cnt[i] = BFS(i);
        if (cnt[i] > max_cnt) {
            max_cnt = cnt[i];
        }
    }

    for (int i = 1; i <= N; i++) {
        if (cnt[i] == max_cnt) {
            cout << i << " ";
        }
    }

    return 0;
}