#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include<algorithm>
#include <utility>
#include <string>
#define ll long long
using namespace std;

int N, M;
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

void propagate(int idx, int start, int end) {
    if (lazy[idx] != 0) {
        tree[idx] += (end - start + 1) * lazy[idx];
        if (start != end) {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void update_range(int idx, int start, int end, int left, int right, ll diff) {
    propagate(idx, start, end);
    if(end < left || start > right) {
        return;
    }
    else if (left <= start && end <= right) {
        tree[idx] += (end - start + 1) * diff;
        if (start != end) {
            lazy[idx * 2] += diff;
            lazy[idx * 2 + 1] += diff;
        }
            return;
    }

    int mid = (start + end) / 2;
    update_range(idx * 2, start, mid, left, right, diff);
    update_range(idx * 2 + 1, mid + 1, end, left, right, diff);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];

    return;
}

ll query(int idx, int start, int end, int left, int right) {
    propagate(idx, start, end);
    if (end < left || start > right) {
        return 0;
    }
    else if (left <= start && end <= right) {
        return tree[idx];
    }

    int mid = (start + end) / 2;
    ll lsum = query(idx * 2, start, mid, left, right);
    ll rsum = query(idx * 2 + 1, mid + 1, end, left, right);
    return tree[idx] = lsum + rsum;
}

void printtree() {
    cout << "tree : ";
    for (int i = 0; i < 20; ++i) {
        cout << tree[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    build(1,1,N);
    //printtree();
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a,b;
        cin >> a >> b;
        if (a == 1) {
            int c, d;
            cin >> c >> d;
            update_range(1, 1, N, b, c, d);
            //printtree();
        }
        else {
            cout << query(1, 1, N, b, b) << "\n";
        }
    }

    
    return 0;
}