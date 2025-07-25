#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

int n;
int arr[2223][2223] = { 0, };
int dist[2223][2223];
priority_queue<pair<int,pair<int, int>>> pq;

int dx[3] = { 0,1 };
int dy[3] = { 1,0 };

int checkbound(int i, int j) {
    if (i < 1 || j < 1 || i > n || j > n) return 0;
    return 1;
}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            dist[i][j] = INT_MAX;
        }
    }

    dist[1][1] = 0;
    pq.push({ 0, {1,1} });
    while (!pq.empty()) { // pq.first = 현재 칸에서 사용한 코인 개수
        auto cur = pq.top();
        int curcoin = -cur.first; // 현재 칸에서 사용한 코인 개수
        int cy = cur.second.first;
        int cx = cur.second.second;
        int curvalue = arr[cy][cx]; // 현재 칸의 가격
        pq.pop();

        if (curcoin > dist[cy][cx]) continue; // dist배열 = 현재 칸까지 도달할 수 있는 최소 비용

        for (int i = 0; i < 2; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            int nextcoin = curcoin;
            if (checkbound(ny, nx)) { // 현재 칸보다 작은 쪽으로만 이동할 수 있음
                if (arr[ny][nx] >= curvalue) { // 다음 칸이 현재 칸보다 큰 경우
                    nextcoin = arr[ny][nx] - curvalue + 1 + curcoin; // 코인을 늘린다.
                }
                else nextcoin = 0 + curcoin; // 그냥 이동이 가능한 경우 코인을 늘릴 필요 없음
                //int nvalue = arr[ny][nx] + nextcoin;

                if (nextcoin < dist[ny][nx]) {
                    dist[ny][nx] = nextcoin;
                    pq.push({ -nextcoin, {ny,nx} });
                }
            }
        }
    }

    //cout << endl;
    //for (int i = 1; i <= n; i++) {
    //    for (int j = 1; j <= n; j++) {
    //        cout << dist[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    cout << dist[n][n];

    return 0;
}