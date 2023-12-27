#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int l, int r, int m) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) 
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void bottomUpMergeSort(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    for (int size = 1; size <= n - 1; size = 2*size) {
        for (int l_start = 0; l_start < n - 1; l_start += 2*size) {
            // Find ending point of left sub array. mid+1 is starting point of right
            int m = l_start + size - 1;
            int r_end = min(l_start + 2*size - 1, n - 1);


            // Merge Subarrays arr[l_start...m] & arr[m+1...r_end]
            merge(arr, l_start, r_end, m);
        }
    }
}

int main() {
    vector<int> arr;
    int n, element;

    cout << "请输入元素的数量：";
    cin >> n;

    cout << "请输入 " << n << " 个元素：";
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        arr.push_back(element);
    }

    bottomUpMergeSort(arr);

    cout << "排序后的数组：";
    for (int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}