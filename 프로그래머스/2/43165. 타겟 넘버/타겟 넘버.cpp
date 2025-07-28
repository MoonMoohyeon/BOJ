#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int cnt = 0;
vector<int> num;
int tg;

void DFS(int sum, int idx) {
    idx++;
    if(sum == tg && idx == num.size()) {
        cnt++;
    }
    if(idx == num.size()) {
        return;
    }
    DFS(sum + num[idx], idx);
    DFS(sum - num[idx], idx);
    return;
}

int solution(vector<int> numbers, int target) {
    num = numbers;
    tg = target;
    
    DFS(0, -1);
    return cnt;
}