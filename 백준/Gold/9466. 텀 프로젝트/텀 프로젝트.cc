#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <climits>
using namespace std;

int T, N;
int graph[100001];
int indegree[100001];
queue<int> q;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
        사이클이 있는 집합의 수를 센다.
        전체 숫자에서 집합의 수를 뺀다.
        아무에게도 선택받지 않은 학생(in-degree가 0)은 절대 팀(사이클)이 될 수 없다.
        팀을 이룬 학생들은 indegree가 1 이상이다.
    */

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            graph[i] = 0;
            indegree[i] = 0;
        }

        for (int i = 1; i <= N; i++) {
            cin >> graph[i];
            indegree[graph[i]]++;
        }

        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int current = q.front();
            q.pop();

            int next = graph[current];
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }

        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                ans++;
            }
            //cout << indegree[i] << " ";
        }

        cout << ans << "\n";
    }


    return 0;
}
