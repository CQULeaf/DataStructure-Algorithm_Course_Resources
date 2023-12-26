#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void placeCar(int car, vector<vector<int>>& tracks) {
    for (vector<int>& track : tracks) {
        if (track.back() > car) {
            track.push_back(car);
            return;
        }
    }
    tracks.push_back(vector<int>{car});
}

void printResult (int car, const vector<vector<int>>& tracks) {
    for (const auto& track : tracks) { // we use `vector` instead of `queue` because `queue` doesn't allow traversing
        if (find(track.begin(), track.end(), car) != track.end()) {
            for (int i = 0; i < track.size(); ++i) {
                if (i != track.size() - 1) {
                    cout << track[i] << " ";
                }
                else cout << track[i] << endl;
            }
        }
    }
    cout << tracks.size() << endl;
}

/*
void printResult (const vector<vector<int>>& tracks) {
    for (auto& track : tracks) {
        for (int i = 0; i < track.size(); ++i) {
            if (i != track.size() - 1) cout << track[i] << " ";
            else cout << track[i] << endl;
        }
    }
    cout << tracks.size() << endl;
}
Output all the tracks
*/

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tracks;

    for (int i = 0; i < n; ++i) {
        int car;
        cin >> car;
        placeCar(car, tracks);
    }

    printResult(1, tracks);

    system("pause");
    return 0;
}