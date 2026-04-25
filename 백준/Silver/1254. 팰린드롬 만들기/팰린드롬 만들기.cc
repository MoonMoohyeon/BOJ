#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include<algorithm>
#include <utility>
#include <string>
using namespace std;

int ispel(string& str) {
    int left = 0;
    int right = str.size() - 1;
    int flag = 1;
    while (left < right) {
        if (str[left++] != str[right--]) {
            flag = 0;
            break;
        }
    }

    return flag;
}

//void search(string& str) {
//    int addidx = str.size() - 2;
//
//    cout << str << " " << ispel(str) << "\n";
//    while (!ispel(str)) {
//        str += str[addidx--];
//        cout << "str : " << str << "\n";
//    }
//
//    cout << str.size();
//}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string S;
    cin >> S;
    
    int idx = 0;
    string temp = S;
    while (!ispel(temp)) {
        temp = S.substr(idx++);
    }
    //cout << temp.size() << " " << (idx - 1) * 2 << "\n";
    int plus = (idx - 1) * 2;
    if (plus < 0) plus = 0;
    cout << temp.size() + plus;
    
    return 0;
}