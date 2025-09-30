#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int R, C, K;
char map[6][6];
int visited[6][6] = { 0, };
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int srcy, srcx, dsty, dstx;
int ans = 0;

void search(int cy, int cx, int cnt) {
    if (cy == dsty && cx == dstx && cnt == K) {
        ans++;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];

        if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
        if (visited[ny][nx] != 0) continue;
        if (map[ny][nx] == 'T') continue;

        visited[ny][nx] = 1;
        search(ny, nx, cnt + 1);
        visited[ny][nx] = 0;
    }
}

int main(int argc, char* argv[]) {
    
    scanf("%d %d %d", &R, &C, &K);
    
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            scanf(" %c", &map[i][j]);
        }
    }

    srcy = R - 1;
    srcx = 0;

    dsty = 0;
    dstx = C - 1;

    visited[srcy][srcx] = 1;
    search(srcy, srcx, 1);
    printf("%d", ans);


    return 0;
}
