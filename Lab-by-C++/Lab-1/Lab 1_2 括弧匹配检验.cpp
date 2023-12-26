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
        if (mapping.find(character) != mapping.end()) {
            if (myStack.empty() || myStack.top() != mapping[character])
                return "Wrong";
            myStack.pop();
        }
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
