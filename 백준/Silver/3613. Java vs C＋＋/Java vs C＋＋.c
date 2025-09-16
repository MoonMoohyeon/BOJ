#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[201];
char ans[201];

void convertJava() {
	ans[0] = string[0];
	int ansidx = 1;
	int len = strlen(string);
	for (int i = 1; i < len; ++i) {
		if (string[i] == '_') {
			ans[ansidx++] = string[++i] - 32; // 대문자 변환 
		}
		else {
			ans[ansidx++] = string[i];
		}
	}
	ans[ansidx] = '\0';
}

void convertC() {
	ans[0] = string[0];
	int ansidx = 1;
	int len = strlen(string);
	for (int i = 1; i < len; ++i) {
		if (string[i] >= 'A' && string[i] <= 'Z') {
			ans[ansidx++] = '_';
			ans[ansidx++] = string[i] + 32; // 대문자 변환 
		}
		else {
			ans[ansidx++] = string[i];
		}
	}
	ans[ansidx] = '\0';
}

int main(int argc, char* argv[]) {
	scanf("%s", string);

	int has_uppercase = 0;
	int has_underscore = 0;
	int error = 0;
	if (string[0] < 'a' || string[0] > 'z') error = 1;

	if (!error) {
		int len = strlen(string); // len 변수를 따로 빼서 한 번만 계산하도록 수정하기.
		for (int i = 0; i < len; ++i) {
			// 허용되지 않는 문자 검사
			if (!((string[i] >= 'a' && string[i] <= 'z') ||
				(string[i] >= 'A' && string[i] <= 'Z') ||
				string[i] == '_')) {
				error = 1;
				break;
			}

			if (string[i] >= 'A' && string[i] <= 'Z') {
				has_uppercase = 1;
			}
			if (string[i] == '_') {
				has_underscore = 1;
				// _가 연속되거나, 마지막 글자가 _인 경우
				if (i > 0 && (string[i - 1] == '_' || i == len - 1)) {
					error = 1;
					break;
				}
			}
		}
	}

	// 에러 검사
	if (has_underscore && has_uppercase) {
		error = 1;
	}
	if (error) {
		printf("Error!\n");
	}
	else {
		if (has_underscore) {
			convertJava();
		}
		else if (has_uppercase) {
			convertC();
		}
		else {
			strcpy(ans, string);
		}
		printf("%s\n", ans);

		return 0;
	}
}