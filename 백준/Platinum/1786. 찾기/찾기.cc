#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#define MAXSIZE 1000001
using namespace std;

string T, P;

vector<int> computePi(const string& pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);
    int j = 0; // 접두사 비교 인덱스

    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j - 1]; // 이전 접두사 정보로 이동

        if (pattern[i] == pattern[j]) {
            j++;
            pi[i] = j; // pi[i]에 접두사-접미사 일치 길이 저장
        }
    }
    return pi;
}

vector<int> KMP(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> output;
    vector<int> pi = computePi(pattern);
    vector<int> result; // 패턴이 나타난 위치 저장
    int j = 0; // 패턴의 비교 인덱스

    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j])
            j = pi[j - 1]; // 점프

        if (text[i] == pattern[j]) {
            if (j == m - 1) { // 패턴 끝까지 일치하면 찾음
                result.push_back(i - m + 1); // 시작 위치 저장
                j = pi[j]; // 다음 탐색을 위해 j 이동
            }
            else {
                j++; // 패턴의 다음 문자 비교
            }
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    getline(cin, T);
    getline(cin, P);

    vector<int> matches = KMP(T, P);
    cout << matches.size() << "\n";
    for (int idx : matches) cout << idx + 1 << " ";

    return 0;
}