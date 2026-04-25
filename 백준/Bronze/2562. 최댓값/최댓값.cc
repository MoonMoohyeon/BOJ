#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main(void)
{
    int arr[9];
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = 0;
    int index = 0;
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            index = i;
        }
    }

    printf("%d\n", max);
    printf("%d", ++index);
    
    return 0;
}
