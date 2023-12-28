#include <iostream>
#include <vector>

using namespace std;

long merge(vector<int>& arr, int l, int m, int r) {
    long count = 0;
    int i = l, j = m + 1;
    vector<int> temp;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            count += (m + 1 - i);
        }
    }
    while (i <= m) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); ++k) {
        arr[l + k] = temp[k];
    }
    
    return count;
}

long mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        long count = mergeSort(arr, l, m) + mergeSort(arr, m + 1, r);
        count += merge(arr, l, m, r);
        return count;
    } else return 0;
}

int main() {
    int t;
    cin >> t;
    vector<long> results(t);

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        results[i] = mergeSort(arr, 0, n - 1);
    }

    for (int i = 0; i < t; ++i) {
        cout << "Scenario #" << i + 1 << ":" << endl;
        cout << results[i] << endl;
        cout << endl;
    }

    system("pause");
    return 0;
}
