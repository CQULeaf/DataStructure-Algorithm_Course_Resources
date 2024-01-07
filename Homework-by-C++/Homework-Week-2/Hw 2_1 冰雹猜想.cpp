#include <iostream>
#include <vector>

using namespace std;

int hail_conjecture(int n, int count) {
    vector<int> number_list;
    number_list.push_back(n);
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else if (n % 2 == 1)
        {
            n = n * 3 + 1;
        }
        number_list.push_back(n);
        count += 1;
    }
    number_list.push_back(1);
    for (int i = 0; i < count; ++i) {
        if (i == count - 1) cout << number_list[i];
        else cout << number_list[i] << " ";
    }
    cout << endl;
    return count;
}

int main() {
    int n;
    cin >> n;

    int result = hail_conjecture(n, 1);
    cout << "count = " << result << endl;

    system("pause");
    return 0;
}