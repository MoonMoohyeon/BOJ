#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int N;
vector<int> graph[1000001];
int visited[1000001];
int DP[1000001][2]; // 1 = 얼리어답터일 때, 2 = 얼리어답터가 아닐 때

void DFS(int start) {
    visited[start] = 1;

    DP[start][1] = 1; // 모든 노드에 대하여 기본 초기화.
    DP[start][0] = 0;

    for (auto i = graph[start].begin(); i != graph[start].end(); i++) {
        if (visited[*i]) continue;
        DFS(*i);
        DP[start][0] += DP[*i][1];
        DP[start][1] += min(DP[*i][1], DP[*i][0]);
    }

    /*
        부모가 얼리어답터가 아닐 때 = 자식 노드들이 얼리어답터일 때의 합
        부모가 얼리어답터일 때 = 자식 노드들의 최소값의 합
    */
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //for (int i = 1; i <= N; i++) {
    //    DP[i][1] = 1; // 리프 노드에 대하여
    //    DP[i][0] = 0; // <-- 이 코드들이 DFS 내부로 들어가야 함. 올바르지 않은 추측과 로직.
    //}


    /*
        힌트 : 각 노드에 대해 현재 노드가 얼리어답터일 때와 얼리 어답터가 아닐 때를 DP
        힌트2 : 리프 노드부터 올라가기.
    */

    DFS(1);
    cout << min(DP[1][0], DP[1][1]);

    return 0;
}