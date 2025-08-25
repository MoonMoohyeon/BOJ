#include <iostream>
#include <string>
using namespace std;

string str;
char op[51];
string operands[51];
int numbers[51];

int main() {

	cin >> str;

	char i = 0;
	int opcnt = 0;
	int opercnt = 0;
	string temp;

	for(char i=0; i<str.size(); ++i) {
		if (str[i] == '-') {
			op[opcnt++] = str[i];
			operands[opercnt++] = temp;
			temp = "";
		}
		else if (str[i] == '+') {
			op[opcnt++] = str[i];
			operands[opercnt++] = temp;
			temp = "";
		}
		else {
			temp += str[i];
		}
	}
	operands[opercnt] = temp;

	for (int i = 0; i <= opercnt; ++i) {
		numbers[i] = stoi(operands[i]);
	}

	//for (int i = 0; i <= opercnt; ++i) {
	//	cout << numbers[i] << "\n";
	//}

	/*
		- 가 한번이라도 나오면 뒤에 나오는 +들을 모두 묶어서 뺄 수 있다.
		- 는 그대로 뺄 수 있다.
	*/

	int ans = numbers[0];
	int flag = 0;
	for (int i = 0; i <= opercnt; ++i) {
		if (op[i] == '-') {
			flag = 1;
		}
		//if (op[i] == '+') {
		//	flag = 0;
		//}
		if (flag) {
			ans -= numbers[i+1];
		}
		else {
			ans += numbers[i+1];
		}

		//cout << ans << "\n";
	}

	cout << ans;

	return 0;
}