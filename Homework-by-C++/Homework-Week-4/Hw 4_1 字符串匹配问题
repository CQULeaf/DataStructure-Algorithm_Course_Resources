#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <vector>

std::string is_valid(const std::string &s) {
    std::stack<char> stack;
    std::unordered_map<char, char> mapping = {
        {')', '('},
        {']', '['},
        {'}', '{'},
        {'>', '<'}
    };
    std::string order = "<([{";

    for (char charact : s) {
        if (order.find(charact) != std::string::npos) {
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
    std::cin >> n;
    std::vector<std::string> results;

    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        results.push_back(is_valid(s));
    }

    for (const auto &res : results)
        std::cout << res << std::endl;

    return 0;
}
