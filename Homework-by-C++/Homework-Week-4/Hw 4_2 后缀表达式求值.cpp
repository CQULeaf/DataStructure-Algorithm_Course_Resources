#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int evaluate_postfix(stack<int>& s, const string& op) {
    if (s.size() < 2) {
        cout << "Expression Error: " << (s.empty() ? 0 : s.top()) << endl;
        return -1;
    }

    int second = s.top(); s.pop();
    int first = s.top(); s.pop();

    if (op == "+") s.push(first + second);
    else if (op == "-") s.push(first - second);
    else if (op == "*") s.push(first * second);
    else if (op == "/") {
        if (second == 0) {
            cout << "Error: " << first << "/0" << endl;
            return -1;
        }
        s.push(first / second);
    } else {
        cout << "Expression Error: " << (s.empty() ? 0 : s.top()) << endl;
        return -1;
    }

    return 0;
}

int main() {
    stack<int> s;
    string token;

    while (cin >> token) {
        if (token == "#") break;

        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            try {
                s.push(stoi(token));
            } catch (const invalid_argument& ia) {
                cerr << "Invalid argument: " << token << endl;
                return -1;
            } catch (const out_of_range& oor) {
                cerr << "Out of range: " << token << endl;
                return -1;
            }
        } else {
            if (evaluate_postfix(s, token) == -1) return -1;
        }
    }

    if (s.size() != 1) {
        cout << "Expression Error: " << s.top() << endl;
        return -1;
    }

    cout << s.top() << endl;

    system("pause");
    return 0;
}
