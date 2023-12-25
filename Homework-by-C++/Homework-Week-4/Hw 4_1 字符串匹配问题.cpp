#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

string is_valid(const string& s) {
    stack<char> stack;
    unordered_map<char, char> mapping = {
        {')', '('},
        {']', '['},
        {'}', '{'},
        {'>', '<'}
    };
    string order = "<([{";

    for (char charact : s) {
        if (order.find(charact) != string::npos) {
            if (!stack.empty() && order.find(stack.top()) < order.find(charact))
                return "NO";
            stack.push(charact);
        } else if (mapping.find(charact) != mapping.end()) {
            if (stack.empty() || mapping[charact] != stack.top())
                return "NO";
            stack.pop();
        } else {
            return "NO";
        }
    }

    return stack.empty() ? "YES" : "NO";
}

int main() {
    int n;
    cin >> n;
    vector<string> results;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        results.push_back(is_valid(s));
    }

    for (const auto &res : results)
        cout << res << endl;

    return 0;
}
