#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <climits>
using namespace std;

int T, day, month, triple, year;
int needed_day[13];
int DP[13];
// int visited[13];
int ans;

/*
    한 달 단위로 비용을 계산한다.
    1. 해당 월에 필요한 일 * 일간 비용
    2. 해당 월에 월간 이용권 사용
    3. 해당 월에 3개월 이용권 사용
    
    DP[n] = n월까지의 최소 비용
    DP[n] = min(DP[n-1] + 일간 비용, DP[n-1] + 월간 비용, DP[n-3] + 3개월권 비용)

    연간 이용권은 따로 생각한다.
*/

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ans = INT_MAX;
    cin >> T;

    for(int q=1; q<=T; q++) {
        cin >> day >> month >> triple >> year; // 개선점 : 이용권 가격을 배열로 묶기
        for(int i=1; i<=12; i++) {
            cin >> needed_day[i];
            DP[i] = 0;
        }

        // 1월 비용 계산
        int dm, t;
        int daycost, monthcost, triplecost;
        daycost = needed_day[1] * day; // 개선점 : 불필요한 임시 변수 사용 자제하고 깔끔하게 만들기
        monthcost = month;
        triplecost = triple;
        dm = min(daycost, monthcost);
        t = triplecost;
        DP[1] = min(dm, t);
        
        // 2월 비용 계산
        daycost = needed_day[2] * day;
        monthcost = month;
        triplecost = triple;
        dm = DP[1] + min(daycost, monthcost);
        t = triplecost;
        DP[2] = min(dm, t);

        // 3월 비용 계산
        daycost = needed_day[3] * day;
        monthcost = month;
        triplecost = triple;
        dm = DP[2] + min(daycost, monthcost);
        t = triplecost;
        DP[3] = min(dm, t);

        for(int i=4; i<=12; i++) { // 4월부터 DP 완성시키기
            daycost = needed_day[i] * day;
            monthcost = month;
            triplecost = triple;
            dm = DP[i-1] + min(daycost, monthcost);
            t = DP[i-3] + triple;
            DP[i] = min(dm, t);
        }

        // cout << "\nDP : ";
        // for(int i=1; i<=12; i++) {
        //     cout << DP[i] << " ";
        // }

        if(year > DP[12]) { // 연간 이용권과 가격 비교하기
            cout << "#" << q << " " << DP[12] << "\n";
        }
        else {
            cout << "#" << q << " " << year << "\n";
        }
    }

    return 0;
}