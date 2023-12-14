#include <iostream>
#include <vector>
using namespace std;

void find_prime_factors(int number) {
    vector<bool> prime(number + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= number; i++) {
        if (prime[i]) {
            for (int j = i * 2; j <= number; j += i) {
                prime[j] = false;
            }
        }
    }

    bool firstPrint = true;
    for (int i = 2; i <= number; i++) {
        if (prime[i] && number % i == 0) {
            if (!firstPrint) {
                cout << " ";
            }
            cout << i;
            firstPrint = false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    find_prime_factors(n);
    return 0;
}