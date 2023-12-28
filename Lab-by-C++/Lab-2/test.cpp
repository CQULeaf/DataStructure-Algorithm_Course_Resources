#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& arr, int left, int mid, int right) {
    int count = 0;
    int i = left, j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            count += (mid - i + 1);
        }
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }

    return count;
}

int mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    int count = mergeSort(arr, left, mid) + mergeSort(arr, mid + 1, right);
    count += merge(arr, left, mid, right);
    return count;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        int swaps = mergeSort(arr, 0, n - 1);
        cout << "Scenario #" << i << ":\n";
        cout << swaps << "\n\n";
    }
    return 0;
}
