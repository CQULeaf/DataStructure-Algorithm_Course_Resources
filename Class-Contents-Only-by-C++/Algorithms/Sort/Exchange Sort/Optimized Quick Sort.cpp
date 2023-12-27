#include <iostream>
#include <vector>

using namespace std;

int medianOfThree(int& a, int& b, int& c) {
    if (a < b) {
        if (b < c)
            return b;
        else if (a < c) 
            return c;
        else
            return a;
    } else {
        if (a < c)
            return a;
        else if (b < c)
            return c;
        else
            return b;
    }
}

int partition(vector<int>& arr, int low, int high) {
    int mid = (low + high) / 2;
    int pivot = medianOfThree(arr[low], arr[mid], arr[high]);
    
    if (pivot == arr[mid]) {
        swap(arr[mid], arr[high]);
    } else if (pivot == arr[low]) {
        swap(arr[low], arr[high]);
    }

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void optimizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        optimizedQuickSort(arr, low, pi - 1);
        optimizedQuickSort(arr, pi + 1, high);
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

    optimizedQuickSort(arr, 0, n - 1);

    cout << "排序后的数组：";
    for (int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}