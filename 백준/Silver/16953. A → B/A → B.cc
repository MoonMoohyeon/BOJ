#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<int,int>> q;

int search(int A, int B) {
    int cnt = 0;
    q.push({A, cnt});
    while(!q.empty()) {
        auto nxtA = q.front();
        q.pop();
        if(nxtA.first == B) return nxtA.second;
        else if(nxtA.first > B) continue;
        else {
            if(nxtA.first * 2 < 1000000000)
                q.push({nxtA.first*2, nxtA.second+1});
            string stA = to_string(nxtA.first);
            stA.append("1");
            if(stoll(stA) < 1000000000)
                q.push({stoll(stA), nxtA.second+1});
            // printf("1 = %d 2 = %d cnt = %d\n", nxtA.first*2, stoi(stA), nxtA.second);
        }
    }
    return -2;
}

int main(void) {
    int A, B;
    scanf("%d %d", &A, &B);
    printf("%d\n", search(A, B) + 1);

    return 0;
}
