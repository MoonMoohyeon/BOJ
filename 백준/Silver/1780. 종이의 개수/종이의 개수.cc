#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int paper[2188][2188];

int pn, zn, nn;
int pc, zc, nc;

void rec(int n, int y, int x) {
    if (n == 1) {
        //cout << "n == 1 " << y << " " << x << "\n";
        if (paper[y][x] == 0) {
            zn++;
        }
        else if (paper[y][x] == 1) {
            pn++;
        }
        else if (paper[y][x] == -1) {
            nn++;
        }
        return;
    }

    pc = zc = nc = 0;
    //cout << "n y x : " << n << " " << y << " " << x << "\n";
    //cout << "pn zn nn : " << pn << " " << zn << " " << nn << "\n";

    for (int i = y; i < y + n; i++) {
        for (int j = x; j < x + n; j++) {
            if (paper[i][j] == 0) zc++;
            if (paper[i][j] == 1) pc++;
            if (paper[i][j] == -1) nc++;
        }
    }

    //cout << "pc zc nc : " << pc << " " << zc << " " << nc << "\n";
    if (pc == n * n) {
        pn++;
        //cout << "pn++" << pn << "\n";
    }
    else if (zc == n * n) {
        zn++;
        //cout << "zn++" << zn << "\n";
    }
    else if (nc == n * n) {
        nn++;
        //cout << "nn++" << nn << "\n";
    }
    else {
        // 재귀 호출

        for (int i = 0; i < n; i += n/3) {
            for (int j = 0; j < n; j += n/3) {
                //if (i == 0 && j == 0) continue;
                //cout << "recursion : " << n << "\n";
                rec(n / 3, y + i, x + j);
            }
        }
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    pn = zn = nn = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    rec(N, 0, 0);
    cout << nn << "\n" << zn << "\n" << pn;

    return 0;
}