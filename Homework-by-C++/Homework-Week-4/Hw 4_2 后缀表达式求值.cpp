#include <iostream>
#include <stack>

using namespace std;

int evaluate_postfix(stack<int>& s, const string op) {
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
    }

    return 0;
}

int main() {
    stack<int> s;
    string token;

    while (cin >> token) {
        if (token == "#") break;

        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            s.push(stoi(token));
        } else {
            if (s.size() < 2) {
                cout << "Expression Error: " << (s.empty() ? 0 : s.top()) << endl;
            }
            if (evaluate_postfix(s, token) == -1) {
                system("pause");
                return -1;
            }
        }

    }

    if (s.size() != 1) {
        cout << "Expression Error: " << s.top() << endl;
        
        system("pause");
        return -1;
    }

    cout << s.top() << endl;

    system("pause");
    return 0;
}