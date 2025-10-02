#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, K;
int visited[100001][2]; // visited[i][0] = 방문 여부 visited[i][1] = 방문 횟수

void BFS(int src, int dst) {
    queue<int> q;
    q.push(src);
    memset(visited, -1, sizeof(visited));
    visited[src][0] = 0;
    visited[src][1] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int move[3] = { cur - 1, cur + 1, cur * 2 };

        for (int i = 0; i < 3; ++i) {
            int next = move[i];
            if (next < 0 || next > 100000) continue;
            if (visited[next][0] == -1) { // 처음 방문
                visited[next][0] = visited[cur][0] + 1;
                visited[next][1] = visited[cur][1];
                q.push(next);
            }
            else if (visited[next][0] == visited[cur][0] + 1) {
                visited[next][1] += visited[cur][1];
            }
        }
    }
}

int main(int argc, char* argv[]) {
    scanf("%d %d", &N, &K);
    
    BFS(N, K);

    /*for (int i = 0; i <= K; ++i) {
        printf("%d ", visited[i][0]);
    }
    printf("\n");
    for (int i = 0; i <= K; ++i) {
        printf("%d ", visited[i][1]);
    }*/

    printf("%d\n%d", visited[K][0], visited[K][1]);

    return 0;
}
