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
string ant = "1";

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;

    if (N == 1) {
        cout << "1" << "\n";
        return 0;
    }

    if (N < 10) {
        for (int i = 1; i < N; ++i) {
            string next_ant = "";

            for (int j = 0; j < ant.size(); ) {
                char curnum = ant[j];
                int cnt = 0;

                int k = j;
                while (ant[k++] == curnum) {
                    cnt++;
                }
                k--;

                next_ant += curnum;
                next_ant += to_string(cnt);

                //cout << "cnum : " << curnum << " cnt : " << cnt << "\n";
                j = k;
            }

            ant = next_ant;
            //cout << ant << "\n";
        }

        char max = '0';
        for (int i = 0; i < ant.size(); ++i) {
            if (ant[i] > max) max = ant[i];
        }
        cout << max;
    }
    else {
        cout << '3';
    }
    
    return 0;
}