#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[10000010];

int main(int argc, char* argv[]) {
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    int cnt = 0;
    char* ptr = strtok(str, " ");
    while (ptr != NULL) {
        cnt++;
        ptr = strtok(NULL, " "); // NULL을 주면 이전 위치부터 시작
    }

    printf("%d\n", cnt);

    return 0;
}