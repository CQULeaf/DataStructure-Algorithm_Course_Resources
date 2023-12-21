#include <iostream>
#include <vector>

using namespace std;

void SimpleSelectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++){
        // 找到未排序部分的最小元素的索引
        int min_index = i;
        for(int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        swap(arr[i], arr[min_index]);
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

    SimpleSelectionSort(arr);

    cout << "排序后的数组：";
    for (int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}