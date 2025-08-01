#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

//#include <bits/stdc++.h>
using namespace std;

int N;
string templ = "____";
string answer[4] = {
	"\"재귀함수가 뭔가요?\"",
	"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
	"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
	"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""
};
void chatBot(int depth) {
	
	string underbar = "";
	for (int i = 0; i < depth; i++) {
		underbar.append(templ);
	}
	cout << underbar+answer[0] << '\n';
	if (depth == N) {
		cout << underbar+"\"재귀함수는 자기 자신을 호출하는 함수라네\"" << '\n';
		cout << underbar+"라고 답변하였지." << '\n';
		return;
	}
	else {
		for (int i = 1; i < 4; i++) {
			cout << underbar +answer[i] << '\n';
		}
	}
	chatBot(depth + 1);
	cout << underbar+"라고 답변하였지." << '\n';
}
int main() {
	cin >> N;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	chatBot(0);
}