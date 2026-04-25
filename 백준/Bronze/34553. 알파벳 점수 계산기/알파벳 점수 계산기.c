#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long

char str[100001];

int main(int argc, char* argv[]) {
    scanf("%s", str);
    int ans = 1;
    int score = 1;
    char pre = str[0];
    int len = strlen(str);
    for (int i = 1; i < len; ++i) {
        if (str[i] > pre) {
            score++;
        }
        else {
            score = 1;
        }

        ans += score;
        pre = str[i];
    }

    printf("%d", ans);

    return 0;
}