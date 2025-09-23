#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 20002

int N;
int deque[MAX_SIZE];
int head = MAX_SIZE / 2, tail = MAX_SIZE / 2;

int empty() {
    return head == tail;
}

int size() {
    return (tail - head + MAX_SIZE) % MAX_SIZE;
}

void push_front(int x) {
    head = (head - 1 + MAX_SIZE) % MAX_SIZE;
    deque[head] = x;
}

void push_back(int x) {
    deque[tail] = x;
    tail = (tail + 1) % MAX_SIZE;
}

int pop_front() {
    if (empty()) return -1;
    int ret = deque[head];
    head = (head + 1) % MAX_SIZE;
    return ret;
}

int pop_back() {
    if (empty()) return -1;
    tail = (tail - 1 + MAX_SIZE) % MAX_SIZE;
    return deque[tail];
}

int front() {
    if (empty()) return -1;
    return deque[head];
}

int back() {
    if (empty()) return -1;
    return deque[(tail - 1 + MAX_SIZE) % MAX_SIZE];
}

int main(int argc, char* argv[])
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        char cmd[20];
        int val;
        scanf(" %s", cmd);
        if (strcmp(cmd, "push_front") == 0) {
            scanf(" %d", &val);
            push_front(val);
        }
        else if (strcmp(cmd, "push_back") == 0) {
            scanf(" %d", &val);
            push_back(val);
        }
        else if (strcmp(cmd, "pop_front") == 0) {
            printf("%d\n", pop_front());
        }
        else if (strcmp(cmd, "pop_back") == 0) {
            printf("%d\n", pop_back());
        }
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(cmd, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(cmd, "front") == 0) {
            printf("%d\n", front());
        }
        else if (strcmp(cmd, "back") == 0) {
            printf("%d\n", back());
        }
    }

    return 0;
}