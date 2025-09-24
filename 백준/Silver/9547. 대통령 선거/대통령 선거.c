#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T, V, C;

int main(int argc, char* argv[]) {
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d %d", &C, &V);
        int pref[101][101];
        int vote[101];
        memset(pref, 0, sizeof(pref));
        memset(vote, 0, sizeof(vote));
        
        int mx_votes = 0;
        int cand_cnt = 0;
        int cand1, cand2;
        cand1 = cand2 = 0;
        for (int i = 1; i <= V; ++i) {
            for (int j = 1; j <= C; ++j) {
                scanf("%d", &pref[i][j]); // i번 유권자의 선호도
                
                if (j == 1) { // 첫번째 투표인 경우 유권자는 가장 선호하는 사람에게 투표함.
                    vote[pref[i][j]]++;
                }
            }
        }

        int winner = 0;
        for (int i = 1; i <= C; ++i) {
            // V/2 보다 크면 과반수
            if (vote[i] * 2 > V) {
                winner = i;
                break;
            }
        }

        if (winner != 0) {
            printf("%d 1\n", winner);
        }
        else {
            int max1_votes = -1, max2_votes = -1;
            for (int i = 1; i <= C; ++i) {
                if (vote[i] > max1_votes) {
                    // 기존 1등을 2등으로 내림
                    max2_votes = max1_votes;
                    cand2 = cand1;
                    // 첫 번째 최다 득표 후보
                    max1_votes = vote[i];
                    cand1 = i;
                }
                else if (vote[i] > max2_votes) {
                    // 두 번째 최다 득표 후보
                    max2_votes = vote[i];
                    cand2 = i;
                }
            }

            int vote_cand1 = 0;
            int vote_cand2 = 0;

            // 다시 선호도 조사
            for (int i = 1; i <= V; ++i) {
                // 각 유권자의 선호도 목록을 순서대로 확인
                for (int j = 1; j <= C; ++j) {
                    if (pref[i][j] == cand1) {
                        vote_cand1++;
                        break;
                    }
                    if (pref[i][j] == cand2) {
                        vote_cand2++;
                        break;
                    }
                }
            }

            if (vote_cand1 > vote_cand2) {
                printf("%d 2\n", cand1);
            }
            else {
                printf("%d 2\n", cand2);
            }
        }
    }
    
    return 0;
}