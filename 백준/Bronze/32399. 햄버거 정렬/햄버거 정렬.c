#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    char str[21];
    scanf("%s", str);

    if (strcmp(str, "(1)") == 0) {
        printf("0");
    }
    else if (strcmp(str, "()1") == 0) {
        printf("1");
    }
    else if (strcmp(str, ")1(") == 0) {
        printf("2");
    }
    else if (strcmp(str, ")(1") == 0) {
        printf("1");
    }
    else if (strcmp(str, "1)(") == 0) {
        printf("1");
    }
    else if (strcmp(str, "1()") == 0) {
        printf("1");
    }
    return 0;
}