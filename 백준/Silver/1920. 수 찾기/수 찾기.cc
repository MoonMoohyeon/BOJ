#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <string.h>
using namespace std;

int arr[100001];

int N, M;

int find(int target)
{
    int front = 0;
    int tail = N - 1;
    int mid;

    while(front <= tail)
    {
        mid = (front + tail) / 2;
        if(target == arr[mid])
        {
            return 1;
        }
        else
        {
            if(target < arr[mid])
            {
                tail = mid - 1;
            }
            else
            {
                front = mid + 1;
            }
        }
    }

    return 0;
}

int main(void)
{
    int num;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+N);

    scanf("%d", &M);
    for(int i=0; i<M; i++)
    {
        scanf("%d", &num);
        printf("%d\n", find(num));
    }
    return 0;
}
