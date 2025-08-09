#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    int marked = 0;
    Node *left = NULL;
    Node *right = NULL;
};

void DFS(Node *num)
{
    num->marked = 1;
    if (num->left != NULL)
        DFS(num->left);
    if (num->right != NULL)
        DFS(num->right);
}

int main(void)
{
    int n, s;
    scanf("%d", &n);
    struct Node *arr;
    arr = (Node *)malloc(sizeof(Node) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].val);
        if (i - arr[i].val >= 0)
            arr[i].left = &arr[i - arr[i].val];
        if (i + arr[i].val < n)
            arr[i].right = &arr[i + arr[i].val];
    }
    scanf("%d", &s);
    DFS(&arr[s - 1]);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].marked == 1)
            count++;
    }

    printf("%d\n", count);
    free(arr);
    return 0;
}
