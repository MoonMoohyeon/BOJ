#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int max(int x, int y) {
    if(x > y) return x;
    else return y;
}

int main()
{
    char str1[1000];
    char str2[1000];

    scanf("%s", str1);
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // printf("%s %s %d %d\n", str1, str2, len1, len2);

    int lcs[1001][1001] = { {0, } };

    for(int i=1; i<=len1; i++) {
        for(int j=1; j<=len2; j++) {
            if(str1[i - 1] == str2[j - 1]) lcs[i][j] = lcs[i-1][j-1] + 1;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }

    // for(int i=0; i<=len1; i++) {
    //     for(int j=0; j<=len2; j++) {
    //         printf("%d ", lcs[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d\n", lcs[len1][len2]);

    return 0;
}
