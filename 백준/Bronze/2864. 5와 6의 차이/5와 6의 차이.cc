#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
	char A[8], B[8];
	scanf("%s %s", A, B);

	char minA[8], maxA[8], minB[8], maxB[8];

	strcpy(minA, A);
	strcpy(maxA, A);
	strcpy(minB, B);
	strcpy(maxB, B);

	for (int i = 0; i < strlen(A); i++)
	{
		if (A[i] == '6') minA[i] = '5';
		if (A[i] == '5') maxA[i] = '6';
	}

	for (int i = 0; i < strlen(B); i++)
	{
		if (B[i] == '6') minB[i] = '5';
		if (B[i] == '5') maxB[i] = '6';
	}

	printf("%d ", stoi(minA) + stoi(minB));
	printf("%d", stoi(maxA) + stoi(maxB));

	return 0;
}
