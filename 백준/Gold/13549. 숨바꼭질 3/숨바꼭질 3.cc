#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 100001;

struct Node {
    int value;
    int mark = 0;
    int visited = 0;
    Node* front = NULL;
    Node* back = NULL;
    Node* twice = NULL;
};

struct Node arr[MAX];
queue<int> q;

int N, K;

void BFS(int start)
{
    q.push(start);
    while (!q.empty())
    {
        int next = q.front();
        q.pop();
        if (next - 1 >= 0)
        {
            if (arr[next].front->visited == 0)
            {
                q.push(arr[next].front->value);
                arr[next].front->mark = arr[next].mark + 1;
                arr[next].front->visited = 1;
            }
            if (arr[next].front->mark > arr[next].mark + 1)
            {
                q.push(arr[next].front->value);
                arr[next].front->mark = arr[next].mark + 1;
            }
        }
        if (next + 1 < MAX)
        {
            if (arr[next].back->visited == 0)
            {
                q.push(arr[next].back->value);
                arr[next].back->mark = arr[next].mark + 1;
                arr[next].back->visited = 1;
            }
            if (arr[next].back->mark > arr[next].mark + 1)
            {
                q.push(arr[next].back->value);
                arr[next].back->mark = arr[next].mark + 1;
            }
        }
        if (next * 2 < MAX)
        {
            if (arr[next].twice->visited == 0)
            {
                q.push(arr[next].twice->value);
                arr[next].twice->mark = arr[next].mark;
                arr[next].twice->visited = 1;
            }
            if (arr[next].twice->mark > arr[next].mark)
            {
                q.push(arr[next].twice->value);
                arr[next].twice->mark = arr[next].mark;
            }
        }
    }
}

int main(void)
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < MAX; i++)
    {
        Node temp;
        temp.value = i;
        arr[i] = temp;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (i > 0)
            arr[i].front = &arr[i - 1];
        if (i < MAX)
            arr[i].back = &arr[i + 1];
        if (i * 2 < MAX)
            arr[i].twice = &arr[i * 2];
    }

    BFS(N);
    arr[N].mark = 0;
    /*for (int i = 0; i < K; i++)
    {
        printf("%d = %d\n",i, arr[i].mark);
    }*/
    printf("%d", arr[K].mark);

    return 0;
}