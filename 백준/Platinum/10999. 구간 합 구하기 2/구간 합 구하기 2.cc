#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long

ll arr[1000001];
ll tree[4000004];
ll lazy[4000004];

ll build(int idx, int start, int end) {
    if (start == end) {
        return tree[idx] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[idx] = build(idx * 2, start, mid) + build(idx * 2 + 1, mid + 1, end);
}

void propagation(int idx, int start, int end) {
    if (lazy[idx] != 0) {
        tree[idx] += lazy[idx] * (end - start + 1);
        if (start != end) {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void update_range(int idx, int start, int end, int left, int right, ll diff) {
    propagation(idx, start, end);

    if (end < left || start > right) {
        return;
    }
    else if (left <= start && end <= right) {
        tree[idx] += diff * (end - start + 1);
        if (start != end) {
            lazy[idx * 2] += diff;
            lazy[idx * 2 + 1] += diff;
        }
        return;
    }
    //else if (start == end) {
    //    tree[idx] += lazy[idx];
    //    return;
    //}

    int mid = (start + end) / 2;
    update_range(idx * 2, start, mid, left, right, diff);
    update_range(idx * 2 + 1, mid + 1, end, left, right, diff);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

ll query(int idx, int start, int end, int left, int right) {
    propagation(idx, start, end);
    if (end < left || start > right) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[idx];
    }

    int mid = (start + end) / 2;
    return query(idx * 2, start, mid, left, right) + query(idx * 2 + 1, mid + 1, end, left, right);
}

void printtree() {
    printf("tree : ");
    for (int i = 0; i < 20; i++) {
        printf("%lld ", tree[i]);
    }
    printf("\n");
}

int N, M, K;

int main(int argc, char** argv) {
    
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; ++i) {
        scanf("%lld", &arr[i]);
    }

    build(1, 1, N);
    //printtree();

    for (int i = 0; i < M + K; ++i) {
        int a;
        scanf("%d", &a);

        if (a == 1) {
            int b, c;
            ll d;
            scanf("%d %d %lld", &b, &c, &d);
            update_range(1, 1, N, b, c, d);
            //printtree();
        }
        else if (a == 2) {
            int b, c;
            scanf("%d %d", &b, &c);
            printf("%lld\n", query(1, 1, N, b, c));
        }
    }

    return 0;
}