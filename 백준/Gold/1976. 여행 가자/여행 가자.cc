#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;

int N, M;
int graph[201][201];
int parent[201];
int ran[201] = { 0, };

int find(int x) {
    if (parent[x] == x) return x;
    else {
        return parent[x] = find(parent[x]);
    }

    return 0;
}

void uni(int a, int b) {
    int roota = find(a);
    int rootb = find(b);

    if (roota != rootb) {
        if (ran[roota] > ran[rootb]) {
            swap(roota, rootb);
        }

        parent[rootb] = roota;

        if (ran[roota] == ran[rootb]) {
            ran[roota]++;
        }
    }
}

bool isunion(int a, int b) {
    if (find(a) == find(b)) return true;
    return false;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 201; i++) {
        parent[i] = i;
    }

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> graph[i][j];
       }
    }

    cin.ignore();
    string plan;
    getline(cin, plan);
    plan += ' ';
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (graph[i][j] == 1) {
                uni(i, j);
            }
        }
    }
    
    int start, cur, cnt, flag;
    flag = cnt = start = 0;
    cur = -1;
    int first, second;
    while (1) {
        cur = plan.find(' ', start);
        if (cur == -1) break;
        string temp = plan.substr(start, cur - start);
        if (temp != "" && cnt == 0) {
            cnt++;
            first = stoi(temp);
        }
        else {
            second = stoi(temp);
            if (isunion(first, second)) {
                flag = 0;
            }
            else {
                flag = 1;
                break;
            }
        }
        start = cur + 1;
    }

    if (flag) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }


    return 0;
}