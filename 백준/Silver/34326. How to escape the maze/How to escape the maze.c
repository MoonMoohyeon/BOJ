#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int N, M;
char map[1001][1001];
int srcy, srcx, dsty, dstx;
int startdir;

// 0:하, 1:우, 2:상, 3:좌
// +1하면 우회전 -1하면 좌회전
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

int leftstart() {
    int cy = srcy;
    int cx = srcx;
    int cdir = startdir;
    int cnt = 0;
    while (cy != dsty || cx != dstx) {
        cdir = (cdir - 1 + 4) % 4; 
        
        int ny = cy + dy[cdir];
        int nx = cx + dx[cdir];
        while (map[ny][nx] == '*') {
            cdir = (cdir + 1) % 4;
            ny = cy + dy[cdir];
            nx = cx + dx[cdir];
        }

        cy = ny;
        cx = nx;
        cnt++;
    }

    return cnt;
}

int rightstart() {
    int cy = srcy;
    int cx = srcx;
    int cdir = startdir;
    int cnt = 0;
    while (cy != dsty || cx != dstx) {
        cdir = (cdir + 1 + 4) % 4;

        int ny = cy + dy[cdir];
        int nx = cx + dx[cdir];
        while (map[ny][nx] == '*') {
            cdir = (cdir - 1 + 4) % 4;
            ny = cy + dy[cdir];
            nx = cx + dx[cdir];
        }

        cy = ny;
        cx = nx;
        cnt++;
    }

    return cnt;
}

int main(int argc, char** argv) {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; ++i) {
        scanf("%s", map[i]);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] == 'S') {
                srcy = i;
                srcx = j;
                if (i + 1 < N && map[i + 1][j] == '.') startdir = 0;       // 아래
                else if (j + 1 < M && map[i][j + 1] == '.') startdir = 1; // 오른쪽
                else if (i - 1 >= 0 && map[i - 1][j] == '.') startdir = 2; // 위
                else if (j - 1 >= 0 && map[i][j - 1] == '.') startdir = 3; // 왼쪽
            }
            if (map[i][j] == 'E') {
                dsty = i;
                dstx = j;
            }
        }
    }

    int lcnt = leftstart();
    int rcnt = rightstart();
    //printf("%d %d\n", lcnt, rcnt);
    if (lcnt == rcnt) printf("SAME");
    else if (lcnt > rcnt) printf("LEFT IS BEST");
    else printf("RIGHT IS BEST");

    return 0;
}