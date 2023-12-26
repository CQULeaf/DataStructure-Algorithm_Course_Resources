#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    int M;
    cin >> M;
    cin.ignore();  // Clear the newline character from the buffer
    queue<string> myQueue;

    for (int i = 0; i < M; ++i) {
        string command;
        cin >> command;

        if (command == "push") {
            string value;
            cin >> value;  // Read the value to be pushed
            cin.ignore();  // Clear the newline character from the buffer
            myQueue.push(value);
        } 
        else if (command == "pop") {
            if (!myQueue.empty()) {
                myQueue.pop();
            } 
        } 
        else if (command == "empty") {
            if (myQueue.empty()) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } 
        else if (command == "query") {
            if (!myQueue.empty()) {
                cout << myQueue.front() << endl;
            } else {
                cout << "Queue is empty, cannot query." << endl;
            }
        }
    }
    system("pause");
    return 0;
}
