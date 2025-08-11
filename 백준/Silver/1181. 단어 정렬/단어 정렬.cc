#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int N;
string str[20001];

int comp(string l, string r) {
    if (l.size() < r.size()) return true;
    if (l.size() > r.size()) return false;
    if (l < r) return true;
    if (l > r) return false;
    return false;
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str[i];
    }

    sort(str, str + N, comp);
    auto ptr = unique(str, str + N); // 중복되지 않은 마지막 요소의 바로 다음 위치를 가리킴
    int end = ptr - str; // 중복 값을 제거한 요소들의 사이즈

    for (int i = 0; i < end; i++) {
        cout << str[i] << "\n";
    }

    return 0;
}