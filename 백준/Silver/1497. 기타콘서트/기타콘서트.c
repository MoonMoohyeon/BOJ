#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long

int N, M;
char guitar[10][51];
ll guitarBit[10];
int selected[10];

int max_songs = 0;
int mincnt = 0;

int check(ll n) {
    int cnt = 0;
    while (n > 0) { // 커니핸 알고리즘, 1의 개수가 몇 개인지 센다.
        n &= (n - 1);
        cnt++;
    }
    return cnt;
}

void recursive(int index) {
    if (index == N) {
        ll cur_state = 0;
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            if (selected[i]) {
                cnt++;
                cur_state |= guitarBit[i];
            }
        }

        int temp = check(cur_state);

        if (temp > max_songs) {
            max_songs = temp; // 최대한 많은 노래를 연주
            mincnt = cnt;
        }
        else if (temp == max_songs) {
            if (mincnt == 0 || cnt < mincnt) {
                mincnt = cnt;
            }
        }

        return;
    }


    selected[index] = 1;
    recursive(index + 1);

    selected[index] = 0;
    recursive(index + 1);
}


int main(int argc, char** argv) {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; ++i) {
        char temp[51];
        scanf("%s %s", guitar[i], &temp);

        for (int j = 0; j < M; ++j) {
            if (temp[j] == 'Y') {
                guitarBit[i] |= (1LL << j);
            }
        }
    }

    recursive(0);
    if (mincnt == 0) printf("-1");
    else printf("%d", mincnt);

    return 0;
}