#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void HeapSort(vector<int>& arr) {
    // 构建最大堆
    make_heap(arr.begin(), arr.end());

    for (int i = arr.size() - 1; i > 0; --i) {
        pop_heap(arr.begin(), arr.begin() + i + 1);
        // 将堆中的最大元素（位于 `arr.begin()`，即堆顶）和范围的最后一个元素（位于 `arr.begin() + i`）交换。
        // 排除已经移动到末尾的最大元素，对剩下的范围（从 `arr.begin()` 到 `arr.begin() + i`）重新进行堆化。
    }
}
// 注意上面这个函数的构造直接使用了algorithm库中操作堆的函数以至于不用我们亲自构建与操作。

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

    HeapSort(arr);

    cout << "排序后的数组：";
    for (int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}