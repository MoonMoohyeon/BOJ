#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long

int N;
char men[10][5];
char women[10][5];
int ans = 0;
int matching[10]; // 인덱스 남자가 값 여자와 매칭됨
int visited[10];

int getscore(char man[], char woman[]) {
    int score = 0;
    for (int i = 0; i < 4; ++i) {
        if (man[i] != woman[i]) score++;
    }

    return score;
}

void check() {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int widx = matching[i];
        sum += getscore(men[i], women[widx]);
    }

    if (sum > ans) ans = sum;
}

void search(int midx) {
    if (midx >= N) {
        check();
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (visited[i]) continue;
        visited[i] = 1;
        matching[midx] = i;
        search(midx + 1);
        visited[i] = 0;
    }
}

int main(int argc, char* argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", men[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%s", women[i]);
    }

    search(0);
    printf("%d", ans);

    return 0;
}