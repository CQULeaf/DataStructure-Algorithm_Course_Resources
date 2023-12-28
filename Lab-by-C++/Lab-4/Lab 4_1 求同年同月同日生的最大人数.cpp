#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> storage;
    int maxCount = 0;
    while (n--) {
        string birth;
        cin >> birth;
        storage[birth]++;
        if (maxCount < storage[birth])
            maxCount = storage[birth];
    }

    cout << maxCount << endl;

    vector<string> maxDates;
    for (const auto& it : storage) {
        if (it.second == maxCount) {
            maxDates.push_back(it.first);
        }
    }

    sort(maxDates.begin(), maxDates.end());

    for (const string& date : maxDates)
        cout << date << endl;

    system("pause");
    return 0;
}