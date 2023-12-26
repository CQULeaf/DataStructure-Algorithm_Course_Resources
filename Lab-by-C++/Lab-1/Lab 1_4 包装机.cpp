#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>

using namespace std;

string packagingMachine(int n, int m, int s_max, vector<queue<char>>& tracks, const vector<int>& operations) {
    stack<char> basket;
    string conveyorBelt;

    for (int op : operations) {
        if (op == 0) {
            if (!basket.empty()) {
                conveyorBelt.push_back(basket.top());
                basket.pop();
            }
        }
        else {
            int trackIndex = op - 1;
            if (!tracks[trackIndex].empty()) {
                if (basket.size() < s_max) {
                    basket.push(tracks[trackIndex].front());
                    tracks[trackIndex].pop();
                } else {
                    conveyorBelt.push_back(basket.top());
                    basket.pop();
                    basket.push(tracks[trackIndex].front());
                    tracks[trackIndex].pop();
                }
            }
        }
    }
    return conveyorBelt;
}

int main() {
    int n, m, s_max;
    cin >> n >> m >> s_max;

    vector<queue<char>> tracks(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char ch;
            cin >> ch;
            tracks[i].push(ch);
        }
    }

    vector<int> operations;
    int op;
    while (cin >> op) {
        if (op != -1) 
            operations.push_back(op);
        else break;
    }

    string result = packagingMachine(n, m, s_max, tracks, operations);
    cout << result << endl;

    system("pause");
    return 0;
}