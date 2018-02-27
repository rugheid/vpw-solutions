#include <bits/stdc++.h>

using namespace std;

int nimSum(vector<int> &v) {
    int sum = 0;
    for (int x: v) {
        sum ^= x;
    }
    return sum;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<int> heaps(N);
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            cin >> heaps[i];
            sum += heaps[i];
        }
        if (sum == 1) {
            cout << t << " HOPELOOS" << endl;
            continue;
        }
        if (N == 1) {
            cout << t << " 1" << endl;
            continue;
        }
        int X = nimSum(heaps);
        if (X == 0) {
            cout << t << " HOPELOOS" << endl;
        } else {
            bool done = false;
            for (int i = 0; i < N; ++i) {
                int afterMove = (heaps[i] ^ X);
                if (afterMove < heaps[i]) {
                    bool all1 = true;
                    int cnt1 = 0;
                    for (int j = 0; j < N; ++j) {
                        int value = (i == j) ? afterMove : heaps[j];
                        if (value > 1) {
                            all1 = false;
                            break;
                        }
                        if (value == 1) cnt1++;
                    }
                    if (all1 && cnt1 % 2 == 0) afterMove ^= 1;
                    if (afterMove >= heaps[i]) continue;
                    done = true;
                    cout << t;
                    for (int j = 0; j < N; ++j) {
                        if (i == j) cout << " " << afterMove;
                        else cout << " " << heaps[j];
                    }
                    cout << endl;
                }
            }
            if (!done) cout << t << " HOPELOOS" << endl;
        }
    }
    return 0;
}

