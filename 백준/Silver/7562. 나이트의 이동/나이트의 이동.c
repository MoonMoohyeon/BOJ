#include <stdio.h>
#include <stdlib.h>

int board[301][301];
int mark[301][301];
int length = 0;

int x[8] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int y[8] = { 2, -2, 1, -1, 2, -2, 1, -1 };

typedef struct {
    int x;
    int y;
} Point;

Point queue[302 * 302];
int front = 0, rear = 0;

void enqueue(int X, int Y) {
    queue[rear].x = X;
    queue[rear].y = Y;
    rear++;
}

Point dequeue() {
    Point p = queue[front];
    front++;
    return p;
}

void BFS(int startX, int startY) {
    enqueue(startX, startY);
    mark[startX][startY] = 1;

    while (front < rear) {
        Point current = dequeue();

        for (int i = 0; i < 8; i++) {
            int newX = current.x + x[i];
            int newY = current.y + y[i];

            if (newX >= 0 && newX < length && newY >= 0 && newY < length && mark[newX][newY] == 0) {
                mark[newX][newY] = 1;
                board[newX][newY] = board[current.x][current.y] + 1;
                enqueue(newX, newY);
            }
        }
    }
}

int main() {
    int test = 0;
    int curX, curY, dstX, dstY;
    scanf("%d", &test);

    for (int i = 0; i < test; i++) {
        scanf("%d", &length);
        scanf("%d %d", &curX, &curY);
        scanf("%d %d", &dstX, &dstY);

        for (int j = 0; j < 301; j++) {
            for (int k = 0; k < 301; k++) {
                board[j][k] = 0;
                mark[j][k] = 0;
            }
        }

        front = rear = 0;

        BFS(curX, curY);
        printf("%d\n", board[dstX][dstY]);
    }

    return 0;
}
