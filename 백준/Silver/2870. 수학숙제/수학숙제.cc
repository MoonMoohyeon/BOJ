#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#define ll long long
using namespace std;

int N;
vector<string> res;

bool comp(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b;
}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string str, temp;
        temp = "";
        cin >> str;
        for (int j = 0; j < str.size(); ++j) {
            if (str[j] >= '0' && str[j] <= '9') {
                temp += str[j];
            }
            else if(temp.size() != 0) {
                int zf = 0;
                for (int k = 0; k < temp.size(); ++k) {
                    if (temp[k] != '0') {
                        zf = 1;
                        break;
                    }
                }

                if (zf) {
                    int idx = temp.find_first_not_of('0');
                    res.push_back(temp.substr(idx));
                }
                else {
                    res.push_back("0");
                }
                temp = "";
            }
        }
        if (temp.size() != 0) {
            int zf = 0;
            for (int k = 0; k < temp.size(); ++k) {
                if (temp[k] != '0') {
                    zf = 1;
                    break;
                }
            }

            if (zf) {
                int idx = temp.find_first_not_of('0');
                res.push_back(temp.substr(idx));
            }
            else {
                res.push_back("0");
            }
        }
    }

    sort(res.begin(), res.end(), comp);
    
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << "\n";
    }

    return 0;
}