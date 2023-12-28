#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

string findSignInProblem(int n, vector<string>& colors) {
    unordered_map<string, int> colorCount;

    for (const string& color : colors) {
        string lowerColor = color;
        transform(lowerColor.begin(), lowerColor.end(), lowerColor.begin(), [](char c){
            return tolower(c);
        });
        colorCount[lowerColor]++;
    }

    int maxCount = 0;
    string signInColor;
    for (const auto& entry : colorCount) {
        if (entry.second > maxCount || (entry.second == maxCount && entry.first < signInColor)) {
            maxCount = entry.second;
            signInColor = entry.first;
        }
    }

    return signInColor;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<string> colors(n);
        for (int j = 0; j < n; ++j) {
            cin >> colors[j];
        }
        string signInColor = findSignInProblem(n, colors);
        cout << signInColor << endl;
    }

    system("pause");
    return 0;
}