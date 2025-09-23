#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50

int N, M;
int map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

typedef struct
{
    int y, x;
} pos;

pos queue[MAX_SIZE * MAX_SIZE];
int head = 0, tail = 0;

void push(int y, int x) {
    pos tmp = { y, x };
    queue[tail++] = tmp;
}

pos pop() {
    return queue[head++];
}

int isEmpty() {
    return head == tail;
}

int checkbound(int y, int x) {
    if (y < 0 || x < 0 || y >= N || x >= M) return 0;
    return 1;
}

void BFS() {
    while (!isEmpty()) {
        pos cur = pop();
        int cy = cur.y;
        int cx = cur.x;

        for (int i = 0; i < 8; ++i) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (checkbound(ny, nx) && dist[ny][nx] == -1) {
                dist[ny][nx] = dist[cy][cx] + 1; // 현재 거리 + 1
                push(ny, nx);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                push(i, j);
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = -1;
            }
        }
    }

    // 모든 상어 위치에서 동시에 BFS 시작
    BFS();

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (dist[i][j] > ans) {
                ans = dist[i][j];
            }
        }
    }

    printf("%d", ans);

    return 0;
}