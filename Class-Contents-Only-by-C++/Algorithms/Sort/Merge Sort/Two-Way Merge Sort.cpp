#include <iostream>
#include <vector>

using namespace std;

void twoWayMerge(vector<int>& arr, int l, int r, int m) {
    // create 2 temp arrays
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);

    // copy the datas to the 2 temp arrays
    for (int i = 0; i < n1; ++i) 
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    // merge the 2 temp arrays into the original array
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

void twoWayMergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        twoWayMergeSort(arr, l, m);
        twoWayMergeSort(arr, m + 1, r);

        twoWayMerge(arr, l, r, m);
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

    twoWayMergeSort(arr, 0, n - 1);

    cout << "排序后的数组：";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}