#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main(void)
{
	int T, N, M;
    int a, b;
    scanf("%d", &T);

    for(int i=0; i<T; i++)
    {
        scanf("%d %d", &N, &M);
        for(int j=0; j<M; j++)
        {
            scanf("%d %d", &a, &b);
        }
        q.push(N-1);
    }
    
    while(!q.empty())
    {
        printf("%d\n", q.front());
        q.pop();
    }

	return 0;
}