#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

int T, X, Y;
int ans;
char graph[51][51];
int dist[51][51] = { 0, };
queue<pair<int, int>> q;
vector<pair<int,pair<int, int>>> edges;
int greed[2605]; // 노드마다 번호를 붙인다.
int mark[2605];
int parent[2605];
int ran[2605];
int nodecnt = 0;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void uni(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra != rb) {
        if (ran[ra] < ran[rb]) {
            swap(ra, rb);
        }
        parent[rb] = ra;
        if (ran[ra] == ran[rb]) ran[ra]++;
    }
}

int isunion(int a, int b) {
    if (find(a) == find(b)) return 1;
    return 0;
}

int isinbound(int y, int x) {
    if (y < 0 || x < 0 || y >= Y || x >= Y) {
        return false;
    }
    return true;
}

void input() {
    // 초기화
    for (int i = 0; i < 2605; i++) {
        parent[i] = i;
        ran[i] = 0;
        greed[i] = 0;
        mark[i] = 0;
    }

    edges.clear();
    ans = 0;
    nodecnt = 0;
    
    // 입력
    cin >> Y >> X;
    for (int i = 0; i < Y; i++) {
        cin >> graph[i];
    }

    // S, A에 대해 unique 노드 번호 생성
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < Y; j++) {
            if (graph[i][j] == 'S' || graph[i][j] == 'K') {
                greed[i * Y + j] = nodecnt++;
            }
        }
    }
}

void BFS(int y, int x, int start) {
    q.push({ y,x });

    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < Y; j++) {
            dist[i][j] = 0;
        }
    }
    dist[y][x] = 1;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (isinbound(ny, nx) && graph[ny][nx] != '1' && dist[ny][nx] == 0) {
                dist[ny][nx] = dist[cy][cx] + 1;
                q.push({ ny,nx });
                if (graph[ny][nx] == 'K' || graph[ny][nx] == 'S') {
                    edges.push_back({ dist[ny][nx] - 1, {start, greed[ny * Y + nx]} }); // cost, from, to
                }
            }
        }
    }
}

int flag = 1;
void solution() {
    // 경로 생성
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < Y; j++) {
            if (graph[i][j] == 'K' || graph[i][j] == 'S') {
                BFS(i, j, greed[i * Y + j]);
            }
        }
    }

    // 크루스칼
    sort(edges.begin(), edges.end());

    int sum, cnt;
    sum = cnt = 0;
    for (const auto& edge : edges) {
        int cost = edge.first;
        int from = edge.second.first;
        int to = edge.second.second;

        if (!isunion(from, to)) {
            uni(from, to);
            sum += cost;
            cnt++;
        }

        if (cnt >= nodecnt - 1) break;
    }
    
    if (nodecnt == 0 || cnt < nodecnt - 1) {
        ans = -1;
    }
    else {
        ans = sum;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    input();
    solution();
    if(flag) cout << ans << endl;

    return 0;
}