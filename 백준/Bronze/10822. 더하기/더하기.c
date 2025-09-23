#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    char str[105];
    scanf("%s", str);
    int len = strlen(str);
    str[len] = ',';
    str[len + 1] = '\0';
    int ans = 0;
    int tidx = 0;
    char temp[10];
    for (int i = 0; i < len + 1; ++i) {
        if (str[i] == ',') {
            temp[tidx] = '\0';
            ans += atoi(temp);
            tidx = 0;
        }
        else {
            temp[tidx++] = str[i];
        }
    }

    printf("%d", ans);

    return 0;
}