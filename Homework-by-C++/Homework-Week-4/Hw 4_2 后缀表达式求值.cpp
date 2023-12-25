#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

int evaluate_postfix(const string& expression) {
    stack<int> stack;

    istringstream iss(expression);
    tring token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1]))) //This checks if token starts with a negative number
        {
            stack.push(stoi(token));
        } 
        else {
            if (stack.size() < 2) {
                cout << "Expression Error: " << (stack.empty() ? 0 : stack.top()) << endl;
                return -1;  // Using -1 as an error code
            }

            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            if (token == "+") {
                stack.push(a + b);
            } else if (token == "-") {
                stack.push(a - b);
            } else if (token == "*") {
                stack.push(a * b);
            } else if (token == "/") {
                if (b == 0) {
                    cout << "Error: " << a << "/0" << std::endl;
                    return -1;
                }
                stack.push(a / b);
            }
        }
    }

    if (stack.size() != 1) {
        cout << "Expression Error: " << stack.top() << endl;
        return -1;
    }

    return stack.top();
}

int main() {
    string input_line;
    getline(cin, input_line);
    input_line.erase(input_line.find('#'));  // Remove the '#' character

    int result = evaluate_postfix(input_line);
    if (result != -1) {
        cout << result << endl;
    }

    return 0;
}
