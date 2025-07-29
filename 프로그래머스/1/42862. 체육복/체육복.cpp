#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    /*
        시작은 n - lost.size();
        lost와 reserve 사이의 차이는 1까지 허용
        최대한 많은 매칭을 만드는 방법을 찾는다. (lost 기준)
        
        1. 간단한 알고리즘
        reserve를 작은 순서부터 lost의 작은 순서를 차례대로 매칭한다.
        불가능하면 건너 뛴다.
        
        증명해야 하는 것
        매칭이 가능한 경우에도 건너 뛰는 경우는 최적이 될 수 없다.
        1 2 4 5
        2 4 6 8
        매칭이 가능한데 건너뛰는 경우, lost 또는 reserve의 값의 차이가
        더 커지기 때문에 최적 값을 찾을 수 없다.
    */
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    vector<int> real_lost;
    vector<int> real_reserve;
    for (int r : reserve) {
        if (!binary_search(lost.begin(), lost.end(), r)) {
            real_reserve.push_back(r);
        }
    }

    for (int l : lost) {
        if (!binary_search(reserve.begin(), reserve.end(), l)) {
            real_lost.push_back(l);
        }
    }
    
    answer = n - real_lost.size();
    
    int i = 0;
    int j = 0;
    
    while (i < real_lost.size() && j < real_reserve.size()) {
        if (abs(real_lost[i] - real_reserve[j]) <= 1) {
            answer++;
            i++;
            j++;
        }
        else if (real_lost[i] > real_reserve[j]) {
            j++;
        }
        else {
            i++;
        }
    }
    
    return answer;
}