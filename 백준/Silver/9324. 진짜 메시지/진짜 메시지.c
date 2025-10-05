#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T;
int DAT[26];
char str[100001];

int main(int argc, char* argv[]) {
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        memset(DAT, 0, sizeof(DAT));
        scanf("%s", str);

        int len = strlen(str);
        int isFake = 0;
        for (int i = 0; i < len; ++i) {
            DAT[str[i] - 'A']++;
            if (DAT[str[i] - 'A'] == 3) {
                if (i + 1 >= len || str[i + 1] != str[i]) {
                    isFake = 1;
                    break;
                }
                DAT[str[i] - 'A'] = 0;
                i++;
            }
        }

        if (isFake) {
            printf("FAKE\n");
        }
        else {
            printf("OK\n");
        }
    }

    return 0;
}