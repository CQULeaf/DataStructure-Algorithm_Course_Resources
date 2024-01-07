#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(const vector<int>& arr, int left, int right, int x) {
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int n, num;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cin >> num;

    for (int i = 0; i < num; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int result = binary_search(arr, b, c, a);
        cout << (result != -1 ? result : -1) << endl;
    }

    system("pause");
    return 0;
}