#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[2000001];
int akaraka(int start, int end) {
    int len = end - start + 1;
    if (len <= 1) {
        return 1;
    }

    int sp, ep;
    sp = start;
    ep = end;
    while (sp < ep) {
        if (str[sp++] != str[ep--]) {
            return 0;
        }
    }

    int mid = start + len / 2;
    int pre = akaraka(start, mid - 1);
    int post = akaraka(end - (len / 2) + 1, end);

    if (pre == 1 && post == 1) return 1;
    
    return 0;
}

int main(void) {

	scanf("%s", str);
	int ans = akaraka(0, strlen(str) - 1);
	if (ans) {
		printf("AKARAKA");
	}
	else {
		printf("IPSELENTI");
	}

	return 0;
}