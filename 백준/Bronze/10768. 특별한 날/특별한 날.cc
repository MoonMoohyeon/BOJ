#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int m, d;
	scanf("%d", &m);
	scanf("%d", &d);
	if (m < 2) printf("Before");
	else if (m == 2 && d == 18) printf("Special");
	else if (m == 2 && d < 18) printf("Before");
	else printf("After");

	return 0;
}