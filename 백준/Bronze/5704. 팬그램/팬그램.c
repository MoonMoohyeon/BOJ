#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DAT[26];

int main(int argc, char* argv[]) {

    char str[210];
    while (1) {
        fgets(str, 210, stdin);
        str[strcspn(str, "\n")] = '\0';

        for (int i = 0; i < 26; ++i) {
            DAT[i] = 0;
        }
        if (strcmp(str, "*") == 0) break;
        int len = strlen(str);
        for (int i = 0; i < len; ++i) {
            DAT[str[i] - 'a']++;
        }

        int flag = 0;
        for (int i = 0; i < 26; ++i) {
            if (DAT[i] == 0) {
                flag = 1;
            }
        }
        if (flag == 0) printf("Y\n");
        else printf("N\n");
    }

    return 0;
}