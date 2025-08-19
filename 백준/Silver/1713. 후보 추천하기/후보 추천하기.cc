#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int N, M;
int frame[21];
pair<int,int> priority[101];

int isvacant() {
    for (int i = 0; i < N; i++) {
        if (frame[i] == 0) {
            return i;
        }
    }

    return -1;
}

int issameschedule(int inp) {
    for (int i = 0; i < N; i++) {
        if (frame[i] == inp) {
            return i;
        }
    }

    return -1;
}

int findleast() {
    int leastval = 1001;
    int leastidx = -1;

    //cout << "Frame : \n";
    //for (int i = 0; i < N; i++) {
    //    cout << frame[i] << " p = " << priority[frame[i]].first << " n = " << priority[frame[i]].second << "\n";
    //}
    //cout << endl;

    for (int i = 0; i < N; i++) {
        if (priority[frame[i]].first < leastval) {
            //cout << "test : " << priority[frame[i]].first << endl;
            //cout << "least : " << leastval << " " << leastidx << endl;
            leastval = priority[frame[i]].first;
            leastidx = i;
        }
        else if (priority[frame[i]].first == leastval) {
            if (priority[frame[i]].second < priority[frame[leastidx]].second) {
                //cout << "1 : " << priority[frame[i]].second << " 2 : " << priority[frame[leastidx]].second << endl;
                //cout << "least2 : " << leastval << " " << leastidx << endl;
                leastidx = i;
            }
        }
    }

    return leastidx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int input;
        cin >> input;

        int position = isvacant();
        if (issameschedule(input) != -1) {
            priority[input].first++;
            continue;
        }
        else if (position == -1) {
            priority[input].first++;
            priority[input].second = i;
            position = findleast();
            int evict = frame[position];
            priority[evict].first = 0;
            priority[evict].second = 0;

            frame[position] = input;
        }
        else {
            priority[input].first++;
            priority[input].second = i;
            frame[position] = input;
        }
    }

    sort(frame, frame + N);
    for (int i = 0; i < N; i++) {
        if(frame[i]) cout << frame[i] << " ";
    }

    return 0;
}