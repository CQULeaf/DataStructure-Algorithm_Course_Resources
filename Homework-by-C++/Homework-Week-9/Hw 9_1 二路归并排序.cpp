#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            ++i;
        } else {
            temp.push_back(arr[j]);
            ++j;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        ++i;
    }

    while (j <= right) {
        temp.push_back(arr[j]);
        ++j;
    }

    for (int k = left, l = 0; k <= right; ++k, ++l) {
        arr[k] = temp[l];
    }

    // Display the entire array after each merge operation
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << ' ';
        }
    }
    cout << endl;
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> unsorted_arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> unsorted_arr[i];
        }

        merge_sort(unsorted_arr, 0, n - 1);
    }

    return 0;
}
