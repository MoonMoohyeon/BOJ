#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[]) {
	int A, P, C;
	scanf("%d %d %d", &A, &P, &C);
	if (A + C > P) printf("%d", A + C);
	else printf("%d", P);

	return 0;
}
