#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

string isValid(const string &s){
    stack<char> myStack;
    unordered_map<char,char> mapping = {
        {')','('},
        {']','['}
    };

    for (char character : s){
        auto it = mapping.find(character);

        // If character is a closing bracket
        if (it != mapping.end()){
            char topElement = myStack.empty() ? '#' : myStack.top();
            myStack.pop();
            
            if (it->second != topElement)
                return "Wrong";
        }
        // If character is an opening bracket or other characters
        else {
            myStack.push(character);
        }
    }
    return myStack.empty() ? "OK" : "Wrong";
}

int main(){
    string s, result;
    cin >> s;
    result = isValid(s);
    cout << result << endl;
    system("pause");
    return 0;
}