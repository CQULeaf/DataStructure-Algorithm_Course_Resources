#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_POS = 100000;

int catchCow(int N, int K) {
    if (N >= K) return N - K;
    vector<int> time(MAX_POS + 1, -1);
    queue<int> q;
    q.push(N);
    time[N] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        vector<int> nextPos = {current - 1, current + 1, current * 2};
        for (int next : nextPos) {
            if (next >= 0 && next <= MAX_POS && time[next] == -1) {
                time[next] = time[current] + 1;
                q.push(next);
            }
        }

        if (time[K] != -1) {
            break;
        }
    }
    return time[K];
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << catchCow(N, K) << endl;
    return 0;
}
