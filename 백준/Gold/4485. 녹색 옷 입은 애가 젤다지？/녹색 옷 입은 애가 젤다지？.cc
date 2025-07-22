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

/*
다익스트라
시작점부터 모든 점까지의 최단거리를 구한다.
힙을 사용한다.
현재 점에서 갈 수 있는 곳을 모두 힙에 넣는다.
가장 짧은 점을 방문한다.
방문하지 않은 모든 점들의 최단거리를 갱신한다.
방문한 점에서 갈 수 있는 곳들을 모두 힙에 넣는다.
반복한다.
*/

int N = 1;
int map[126][126];
int mark[126][126] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int,int>> v[126][126];
priority_queue<pair<pair<int,int>,int>> pq;

bool checkbound(int y, int x) {
    if (x < 0 || y < 0 || x >= N || y >= N) {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int cnt = 0;
    while (true) {
        cin >> N;
        if (N == 0) break;

        // 초기화
        for (int i = 0; i < 126; i++) {
            for (int j = 0; j < 126; j++) {
                mark[i][j] = INT_MAX; // 수정: mark 배열 초기화
                v[i][j].clear();
            }
        }

        for (int i = 0; i < N; i++) { // 입력받기
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (checkbound(nx, ny)) { // 경계 체크
                        v[i][j].push_back({ nx, ny });
                    }
                }
            }
        }

        mark[0][0] = map[0][0]; // 시작점 초기화
        pq.push({ {0, 0}, -map[0][0] }); // 시작지점 인접 노드를 큐에 넣기

        while (!pq.empty()) {
            auto cur = pq.top(); // 큐에서 꺼낸 최소 값
            int cost = -cur.second; // 음수로 저장된 비용 복원
            auto pos = cur.first;
            int cx = pos.first;
            int cy = pos.second;
            pq.pop();

            if (cost > mark[cx][cy]) continue;

            for (auto i = v[cx][cy].begin(); i != v[cx][cy].end(); i++) {
                int nx = i->first;
                int ny = i->second;
                int ncost = cost + map[nx][ny];
                if (ncost < mark[nx][ny]) {
                    mark[nx][ny] = ncost;
                    pq.push({ {nx, ny}, -ncost }); // 음수로 저장
                }
            }
        }
        cnt++;
        cout << "Problem " << cnt << ": " << mark[N - 1][N - 1] << "\n"; // 올바른 출력
    }

    return 0;
}
