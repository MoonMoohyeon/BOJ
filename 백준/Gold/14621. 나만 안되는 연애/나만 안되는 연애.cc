#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int N, M;
char gender[1001];
vector<pair<int, int>> graph[1001];
int mark[1001] = { 0, };
priority_queue<pair<int, int>> pq; // cost, node

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> gender[i];
    }

    int V = M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (gender[a] == gender[b]) {
            V--;
            continue;
        }
        graph[a].push_back({ c,b });
        graph[b].push_back({ c,a });
    }

    pq.push({ 0,1 });
    int sum, cnt;
    sum = cnt = 0;
    while (!pq.empty() && cnt < N) {
        int cost = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if (mark[pos]) continue;
        sum += cost;
        cnt++;
        mark[pos] = 1;

        for (auto i = graph[pos].begin(); i != graph[pos].end(); i++) {
            int ncost = i->first;
            int next = i->second;

            if (mark[next] == 0) {
                pq.push({ -ncost, next });
            }
        }
    }

    //for (int i = 1; i <= N; i++) {
    //    cout << mark[i] << " ";
    //}
    //cout << endl;
    if (cnt < N) cout << "-1";
    else cout << sum;


    return 0;
}