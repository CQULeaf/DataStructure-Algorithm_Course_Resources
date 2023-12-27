#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int>& arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
        }
        if (i < 3) {
            for (int k = 0; k < n; ++k) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    BubbleSort(arr, n);

    system("pause");
    return 0;
}
