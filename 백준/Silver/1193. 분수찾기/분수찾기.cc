#include <iostream>
#include <vector>

using namespace std;

int arr[1001] = { 0, };
bool mark[1001] = { false, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
        1 1/1

        2 1/2 /+
        3 2/1 +/

        4 3/1 +/
        5 2/2 -/+
        6 1/3 -/+

        7 1/4 /+
        8 2/3 +/-
        9 3/2  +/-
        10 4/1 +/-

        11 5/1 +/
        12 4/2 -/+
        13 3/3 -/+
        14 2/4 -/+
        15 1/5 -/+

        16 1/6 /+
        17 2/5 +/-
        18 3/4 +/-
        19 4/3 +/-
        20 5/2 +/-
        21 6/1 +/-


        1 1/1

        2 1/2 /+

        3 2/1 +/
        4 3/1 +/

        5 2/2 -/+
        6 1/3 -/+
        7 1/4 /+

        8 2/3 +/-
        9 3/2  +/-
        10 4/1 +/-
        11 5/1 +/

        12 4/2 -/+
        13 3/3 -/+
        14 2/4 -/+
        15 1/5 -/+
        16 1/6 /+

        17 2/5 +/-
        18 3/4 +/-
        19 4/3 +/-
        20 5/2 +/-
        21 6/1 +/-

        22 7/1 +/-

        1 1/1
        2 1/2 2/1
        3 3/1 2/2 1/3
        4 1/4 2/3 3/2 4/1
        5 5/1 4/2 3/3 2/4 1/5
        6 1/6 2/5 3/4 4/3 5/2 6/1
    */

    int c;
    cin >> c;

    int m, j, flag;
    m = j = 1;
    flag = 1;
    int n = 0;
    int limit = 1;
    if (c == 1) {
        cout << "1/1";
        return 0;
    }
    else if (c == 2) {
        cout << "1/2";
        return 0;
    }
    for (int i = 3; i <= c; i++) {
        n++;
        if (n == limit) {
            n = 0;
            limit++;
            if (flag) flag = 0;
            else flag = 1;
        }

        if (flag) { // 분모가 늘어날 때
            m++;
            if (j > 1) {
                j--;
            }
        }
        else { // 분자가 늘어날 때
            j++;
            if (m > 1) {
                m--;
            }
        }
    }

    cout << j << "/" << m;



    return 0;
}