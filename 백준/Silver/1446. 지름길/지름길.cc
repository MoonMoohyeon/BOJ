#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

int N, M;
vector<pair<int,int>> graph[50001];
int mark[50001];
int point[50001];
int point2[50001];
priority_queue<pair<int, int>> pq; // weight, to

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        graph[0].push_back({ a, a });
        point[i] = b;
        point2[i] = a;
        if (b - a > c) {
            graph[a].push_back({ c, b });
            //cout << "ipush : " << c << " " << b << "\n";
        }
        else {
            graph[a].push_back({ b - a, b });
        }
        if (-(M - b) < 0) {
            graph[b].push_back({ M - b, M });
            //cout << "push : " << (M - b) << " " << M << "\n";
        }
    }

    for (int i = 0; i < 50001; i++) {
        mark[i] = i;
    }

    mark[0] = 0;
    pq.push({ -0,0 });

    // 한 포인트에 도착 했을 때, 다음 포인트까지 걸어가는 경우의 수를 추가해야함.
    while (!pq.empty()) {
        auto cur = pq.top();
        int cost = -cur.first;
        int pos = cur.second;
        pq.pop();
        if (cost > mark[pos]) continue;

        for (int i = 0; i < N; i++) {
            if (point[i] - pos > 0) {
                //cout << "*i - pos = " << point[i] << " pos = " << pos << " cost =  " << cost << " sum =  " << -(point[i] - pos + cost) << "\n";
                pq.push({ -(point[i] - pos + cost) , point[i] });
            }
        }

        for (int i = 0; i < N; i++) {
            if (point2[i] - pos > 0) {
                //cout << "2 *i - pos = " << point2[i] << " pos = " << pos << " cost =  " << cost << " sum =  " << -(point2[i] - pos + cost) << "\n";
                pq.push({ -(point2[i] - pos + cost) , point2[i] });
            }
        }

        for (auto i = graph[pos].begin(); i != graph[pos].end(); i++) {
            int ncost = i->first + cost;
            int npos = i->second;
            if (ncost < mark[npos]) {
                mark[npos] = ncost;
                pq.push({ -ncost, npos });
                //cout << "ncost npos = " << ncost << " " << npos << " mark " << mark[npos] << "\n";
            }
        }

    }

    cout << mark[M];
    

    return 0;
}
