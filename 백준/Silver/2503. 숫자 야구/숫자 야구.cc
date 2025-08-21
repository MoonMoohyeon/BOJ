#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

// 모든 가능한 세 자리 수 순열을 저장할 벡터
vector<vector<int>> candidates;

void generate() {
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            for (int k = 1; k <= 9; ++k) {
                // 세 숫자가 모두 다른 경우에만 후보로 추가
                if (i != j && j != k && i != k) {
                    candidates.push_back({ i, j, k });
                }
            }
        }
    }
}

//void generate() {
//    // 1. 순열을 만들 숫자들 준비
//    vector<int> numbers(9);
//    iota(numbers.begin(), numbers.end(), 1);
//
//    // 2. 9개 중 3개를 뽑기 위한 마스크
//    vector<bool> mask(9, false);
//    for (int i = 0; i < 3; ++i) {
//        mask[i] = true; // 앞 3개를 뽑는다고 표시
//    }
//    sort(mask.begin(), mask.end()); // 오름차순 정렬은 필수
//
//    // 3. 조합(Combination) 생성 루프
//    do {
//        vector<int> current_combination;
//        // 마스크를 기반으로 현재 조합 생성
//        for (int i = 0; i < 9; ++i) {
//            if (mask[i]) {
//                current_combination.push_back(numbers[i]);
//            }
//        }
//
//        // 4. 현재 조합으로 순열(Permutation) 생성 루프
//        // current_combination은 이미 정렬된 상태이므로 바로 next_permutation 사용 가능
//        do {
//            candidates.push_back(current_combination);
//        } while (next_permutation(current_combination.begin(), current_combination.end()));
//
//    // next_permutation으로 마스크 순서 변경 -> 중복 없이 뽑은 숫자
//    } while (next_permutation(mask.begin(), mask.end()));
//
//    /*
//    next_permutation은 이미 정해진 하나의 묶음을 가지고 모든 순서로 줄을 세우는 전문가입니다.
//    {A, B, C}라는 카드 묶음을 이 함수에게 주면,
//    함수는 ACB, BAC, BCA, CAB, CBA 순서로 카드를 재배열해 줍니다.
//    "줄 세우기" 전문가라고 생각하시면 됩니다.
//    3개를 "뽑는" 역할을 하기에 적합하지 않기 때문에 마스크를 사용하며 복잡해졌습니다.
//    */
//}

int check_strikes(const vector<int>& cand, const vector<int>& query) {
    int strike_count = 0;
    for (int i = 0; i < 3; ++i) {
        if (cand[i] == query[i]) {
            strike_count++;
        }
    }
    return strike_count;
}

int check_balls(const vector<int>& cand, const vector<int>& query) {
    int ball_count = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // 위치가 같으면 스트라이크이므로 건너뜀
            if (i == j) continue;
            // 위치는 다르지만 숫자가 같으면 볼
            if (cand[i] == query[j]) {
                ball_count++;
            }
        }
    }
    return ball_count;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    generate();

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string q_str;
        int given_strikes, given_balls;
        cin >> q_str >> given_strikes >> given_balls;

        // 문자열을 정수 벡터로 변환
        vector<int> query_vec;
        for (char c : q_str) {
            query_vec.push_back(c - '0');
        }

        // 조건을 만족하지 않는 후보를 제거하기 위한 임시 벡터
        vector<vector<int>> next_candidates;

        // 모든 후보를 순회하며 조건 검사
        for (const auto& cand : candidates) {
            int calculated_strikes = check_strikes(cand, query_vec);
            int calculated_balls = check_balls(cand, query_vec);

            // 계산된 스트라이크와 볼의 개수가 주어진 값과 일치하는 경우에만
            // 다음 라운드의 후보로 추가
            if (calculated_strikes == given_strikes && calculated_balls == given_balls) {
                next_candidates.push_back(cand);
            }
        }
        // 후보 리스트를 조건을 통과한 것들로 교체
        candidates = next_candidates;
    }

    cout << candidates.size();

    return 0;
}