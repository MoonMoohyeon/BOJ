#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char N[1000001];

void swap(char* first, char* second) {
    char tmp = *first;
    *first = *second;
    *second = tmp;
}

int compare(const void *first, const void *second) {
    
    return *(char*)second - *(char*)first;
}

int main(int argc, char* argv[]) {
    scanf("%s", N);

    int len = strlen(N);
    int zeroflag = 0;
    int sum = 0;
    int sumflag = 0;
    for (int i = 0; i < len; ++i) {
        //printf("n = %d\n", N[i] - '0');
        if (N[i] - '0' == 0) zeroflag = 1;
        sum += N[i] - '0';
    }
    //printf("sum = %d\n", sum);
    if (sum % 3 == 0) sumflag = 1;
    //printf("zf = %d sf = %d\n", zeroflag, sumflag);
    if (!zeroflag || !sumflag) {
        printf("-1");
        return 0;
    }

    qsort(N, len, sizeof(char), compare);

    printf("%s", N);


    return 0;
}
