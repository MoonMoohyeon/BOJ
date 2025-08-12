#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, A, B;
vector<pair<int,int>> graph[100001];
vector<int> path;
int visited[100001] = { 0, };

/*
        DFS로 a에서 b까지 가는 경로를 구한다.
        경로에서 가장 긴 간선을 뺀 나머지 간선의 합을 구한다.
*/
int ans;

void DFS(int start) {
    if (start == B) {
        sort(path.begin(), path.end());
        int idx = 0;
        while (idx < path.size() - 1) {
            ans += path[idx++];
        }
        //cout << endl << "path : ";
        //for (int i = 0; i < path.size(); i++) {
        //    cout << path[i] << " ";
        //}
        //cout << endl;
        return;
    }

    for (auto i = graph[start].begin(); i != graph[start].end(); i++) {
        int next = i->second;
        int ncost = i->first;
        if (visited[next] == 0) {
            visited[next] = ncost;
            path.push_back(ncost);
            DFS(next);
            path.pop_back();
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> A >> B;
    for (int i = 1; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ c,b });
        graph[b].push_back({ c,a });
    }

    visited[A] = 1;
    path.push_back(0);
    DFS(A);
    cout << ans;
    //for (int i = 1; i <= N; i++) {
    //    cout << visited[i] << " ";
    //}

    return 0;
}