#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 翻转函数，翻转arr[0..i]
void flip(vector<int>& arr, int i) {
    reverse(arr.begin(), arr.begin() + i + 1);
}

// 返回最大元素的索引
int findMax(vector<int>& arr, int n) {
    int max_index = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

// 煎饼排序
void PancakeSort(vector<int>& arr) {
    int n = arr.size();
    for (int curr_size = n; curr_size > 1; --curr_size)
    {
        int max_index = findMax(arr, curr_size - 1);

        if (max_index != curr_size - 1) {
            flip(arr, max_index);
            flip(arr, curr_size - 1);
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

    PancakeSort(arr);

    cout << "排序后的数组：";
    for (int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}