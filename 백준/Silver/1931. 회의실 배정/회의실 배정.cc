#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> vec;

int main(void)
{
    int N;
    scanf("%d", &N);
    int t1, t2;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &t1, &t2);
        vec.push_back(make_pair(t2, t1));
    }

    sort(vec.begin(), vec.end());

    /*printf("\n");
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
    {
        printf("%d %d\n", iter->first, iter->second);
    }*/

    int count = 0;
    int prev = 0;
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
    {
        //printf("prev = %d second = %d\n", prev, iter->second);
        if (iter->second >= prev)
        {
            count++;
            prev = iter->first;
        }
    }
    
    printf("%d", count);

    return 0;
}