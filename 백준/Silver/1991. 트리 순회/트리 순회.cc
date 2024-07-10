#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char me;
    node* left;
    node* right;
};

struct node nodes[130];

void pre(char c) {
    printf("%c", (char)nodes[c].me);
    if (nodes[c].left != NULL) {
        pre((char)nodes[c].left->me);
    }
    if (nodes[c].right != NULL) {
        pre((char)nodes[c].right->me);
    }
}

void in(char c) {
    if (nodes[c].left != NULL) {
        in((char)nodes[c].left->me);
    }
    printf("%c", (char)nodes[c].me);
    if (nodes[c].right != NULL) {
        in((char)nodes[c].right->me);
    }
}

void post(char c) {
    if (nodes[c].left != NULL) {
        post((char)nodes[c].left->me);
    }
    if (nodes[c].right != NULL) {
        post((char)nodes[c].right->me);
    }
    printf("%c", (char)nodes[c].me);
}
int main()
{
    int N;
    char t_me, t_left, t_right;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        nodes['A' + i].me = 'A' + i;
        nodes['A' + i].left = NULL;
        nodes['A' + i].right = NULL;
    }

    for(int i=0; i<N; i++) {
        scanf(" %c %c %c", &t_me, &t_left, &t_right);
        if(t_left == '.') {
            nodes[t_me].left = NULL;
        }
        else {
            nodes[t_me].left = &nodes[t_left];
        }
        
        if(t_right == '.') {
            nodes[t_me].right = NULL;
        }
        else {
            nodes[t_me].right = &nodes[t_right];
        }
    }

    pre('A');
    printf("\n");
    in('A');
    printf("\n");
    post('A');
    printf("\n");

    return 0;
}