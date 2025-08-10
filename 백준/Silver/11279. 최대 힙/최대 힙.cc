#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int siz = 0;
int heap[100001] = {0, };

void pop()
{
    if (siz == 0)
    {
        printf("0\n");
        return;
    }
    int retv = heap[1];
    heap[1] = heap[siz];
    if (siz == 1) {
        siz = 0;
        printf("%d\n", retv);
        return;
    }

    int i = 1;
    siz--;
    while (true)
    {
        if (i * 2 > siz)
        {
            break;
        }
        else if (i * 2 + 1 > siz)
        {
            if (heap[i * 2] >= heap[i])
            {
                swap(heap[i * 2], heap[i]);
            }
            break;
        }
        else
        {
            if (heap[i] <= heap[i * 2] && heap[i] <= heap[i * 2 + 1])
            {
                if (heap[i * 2] >= heap[i * 2 + 1])
                {
                    swap(heap[i], heap[i * 2]);
                    i = i * 2;
                }
                else
                {
                    swap(heap[i], heap[i * 2 + 1]);
                    i = i * 2 + 1;
                }
            }
            else if (heap[i] <= heap[i * 2] && heap[i] > heap[i * 2 + 1])
            {
                swap(heap[i], heap[i * 2]);
                i = i * 2;
            }
            else if (heap[i] <= heap[i * 2 + 1] && heap[i] > heap[i * 2])
            {
                swap(heap[i], heap[i * 2 + 1]);
                i = i * 2 + 1;
            }
            else break;
        }
        
    }

    printf("%d\n", retv);
}

void insert(int num)
{
    heap[++siz] = num;
    int i = siz;
    while (i > 1 && heap[i] > heap[i / 2])
    {
        swap(heap[i], heap[i / 2]);
        i /= 2;
    }
}

int main(void)
{
    int N, num;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        if (num == 0)
        {
            pop();
        }
        else
        {
            insert(num);
        }
    }

    return 0;
}