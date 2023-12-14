#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void print(const vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++)
        cout << arr[i] << " ";
    cout << arr[arr.size() - 1];
}

int binary_search(const vector<int>& arr, int target) {
    int begin = 0;
    int end = arr.size() - 1;
    while (begin <= end) {
        int mid = begin + (end - begin) / 2; 
        if (arr[mid] > target)
            end = mid - 1;
        else if (arr[mid] < target)
            begin = mid + 1;
        else
            return mid + 1;
    }
    return 0;
}

int main() {
    int n, m;
    while (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        print(arr);
        cout << endl;

        cin >> m;
        vector<int> res;
        while (m--) {
            int num; cin >> num;
            res.push_back(binary_search(arr, num));
        }
        print(res);
        cout<<endl;
    }

    return 0;
}