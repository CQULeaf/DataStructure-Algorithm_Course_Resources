#include <iostream>
#include <sstream>
#include <string>
#include <stack>

int evaluate_postfix(const std::string& expression) {
    std::stack<int> stack;

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1]))) //This checks if token starts with a negative number
        {
            stack.push(std::stoi(token));
        } 
        else {
            if (stack.size() < 2) {
                std::cout << "Expression Error: " << (stack.empty() ? 0 : stack.top()) << std::endl;
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
                    std::cout << "Error: " << a << "/0" << std::endl;
                    return -1;
                }
                stack.push(a / b);
            }
        }
    }

    if (stack.size() != 1) {
        std::cout << "Expression Error: " << stack.top() << std::endl;
        return -1;
    }

    return stack.top();
}

int main() {
    std::string input_line;
    std::getline(std::cin, input_line);
    input_line.erase(input_line.find('#'));  // Remove the '#' character

    int result = evaluate_postfix(input_line);
    if (result != -1) {
        std::cout << result << std::endl;
    }

    return 0;
}
