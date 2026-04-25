#include <stdio.h>
#include <string.h>

int main(void)
{
	char arr[55];
	scanf("%s", &arr);
	strcat(arr, "??!");
	printf("%s", arr);
	
	return 0;
}