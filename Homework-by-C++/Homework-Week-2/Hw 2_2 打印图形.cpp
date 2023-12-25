#include <iostream>

using namespace std;

void printDiamond(int n) {
    int space, stars;

    for (int i = 1; i <= n; ++i) {
        space = n - i;
        stars = 2 * i - 1;

        for (int j = 1; j <= space; ++j) {
            cout << " ";
        }
        for (int j = 1; j <= stars; ++j) {
            cout << "*";
        }
        for (int j = 1; j <= space; ++j) {
            cout << " ";
        }
        cout << endl;
    }
    
    for (int i = n - 1; i >= 1; --i) {
        space = n - i;
        stars = 2 * i - 1;

        for (int j = 1; j <= space; ++j) {
            cout << " ";
        }
        for (int j = 1; j <= stars; ++j) {
            cout << "*";
        }
        for (int j = 1; j <= space; ++j) {
            cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    
    printDiamond(n);

    system("pause");
    return 0;
}