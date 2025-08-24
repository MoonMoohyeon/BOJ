#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;
string str;
string ans;

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> str;

    int start = 0;
    int cur = -1;
    int cnt = 0;

    int insertpos = -1;

    str += ":";
    while (1) {
        cur = str.find(":", start);
        if (cur == -1) {
            break;
        }

        string temp = str.substr(start, cur - start);
        if (temp != "") {
            cnt++;
            while (temp.size() != 4) {
                temp.insert(temp.begin(), '0');
            }
            temp += ":";
            ans += temp;
        }
        else { // ::가 나온 지점
            insertpos = ans.length();
        }
        start = cur + 1;
    }

    string zeros = "";
    for (int i = 0; i < 8 - cnt; i++) {
        zeros += "0000:";
    }

    if (insertpos != -1) {
        ans.insert(insertpos, zeros);
    }

    ans.erase(ans.end() - 1);
    cout << ans;
    
    return 0;
}