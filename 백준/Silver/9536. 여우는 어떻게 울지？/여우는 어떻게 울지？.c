#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    strlen
    strcmp
    strcpy
    strstr
    strcspn
    strtok
*/

int main(void) {
    int T;
    scanf("%d", &T);
    getchar(); // 줄바꿈 문자 제거

    for (int t = 0; t < T; ++t) {
        char all_sounds[2501]; // 모든 울음소리 저장
        fgets(all_sounds, sizeof(all_sounds), stdin);
        all_sounds[strcspn(all_sounds, "\r\n")] = '\0';

        char animal_cries[100][101];
        int cry_count = 0;

        while (1) {
            char line[201];
            fgets(line, sizeof(line), stdin);
            line[strcspn(line, "\r\n")] = '\0';

            if (strcmp(line, "what does the fox say?") == 0) {
                break;
            }

            char* goes_ptr = strstr(line, "goes ");
            if (goes_ptr != NULL) {
                strcpy(animal_cries[cry_count++], goes_ptr + 5); // 울음소리만 분리해서 추가
            }
        }

        // 토큰화
        char final_result[2501] = ""; // 최종 결과 문자열
        char* token = strtok(all_sounds, " "); // 공백을 기준으로 첫 단어 분리

        while (token != NULL) {
            int is_animal_cry = 0;
            // 현재 단어(token)가 다른 동물의 울음소리 목록에 있는지 확인
            for (int i = 0; i < cry_count; i++) {
                if (strcmp(token, animal_cries[i]) == 0) {
                    is_animal_cry = 1;
                    break;
                }
            }

            // 다른 동물의 울음소리가 아니라면 최종 결과에 추가
            if (!is_animal_cry) {
                strcat(final_result, token);
                strcat(final_result, " "); // 단어 뒤에 공백 추가
            }

            token = strtok(NULL, " "); // 다음 단어 분리
        }

        // 마지막에 추가된 공백 제거
        if (strlen(final_result) > 0) {
            final_result[strlen(final_result) - 1] = '\0';
        }

        printf("%s\n", final_result);
    }

    return 0;
}