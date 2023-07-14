#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

const int MAX = 100001;

struct Node {
    int value;
    int mark = 0;
    Node* front = NULL;
    Node* back = NULL;
    Node* twice = NULL;
    Node* from = NULL;
};

struct Node arr[MAX];
queue<int> q;

void BFS(int start)
{
    q.push(start);
    while (!q.empty())
    {
        int next = q.front();
        q.pop();
        if (next - 1 >= 0 && arr[next].front->mark == 0)
        {
            q.push(arr[next].front->value);
            arr[next].front->mark = arr[next].mark + 1;
            arr[next].front->from = &arr[next];
        }
        if (next + 1 < MAX && arr[next].back->mark == 0)
        {
            q.push(arr[next].back->value);
            arr[next].back->mark = arr[next].mark + 1;
            arr[next].back->from = &arr[next];
        }
        if (next * 2 < MAX && arr[next].twice->mark == 0)
        {
            q.push(arr[next].twice->value);
            arr[next].twice->mark = arr[next].mark + 1;
            arr[next].twice->from = &arr[next];
        }
    }
}

int main(void)
{
    int N, K;
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
    /*for (int i = 0; i <= K; i++)
        printf("%d = %d\n",i, arr[i].mark);*/

    stack<int> st;
    st.push(K);
    int next = arr[K].from->value;
    Node* nextnode;
    while (next != N)
    {
        st.push(next);
        nextnode = arr[next].from;
        next = nextnode->value;
    }
    st.push(N);


    printf("%d\n", arr[K].mark);
    while (1)
    {
        if (st.top() == K)
        {
            printf("%d", st.top());
            return 0;
        }
        if (!st.empty())
        {
            printf("%d ", st.top());
            st.pop();
        }
    }

    return 0;
}