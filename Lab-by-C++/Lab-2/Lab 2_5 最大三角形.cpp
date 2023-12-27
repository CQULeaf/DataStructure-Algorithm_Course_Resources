#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findBiggestPerimeterTriangle(int n, vector<int>& arr) {
    if (n < 3) {
        cout << "小棍的个数不能组成三角形" << endl;
    } else {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 2; ++i) {
            if (arr[i] + arr[i + 1] > arr[i + 2]) {
                cout << "最大三角形的周长是" << arr[i] + arr[i + 1] + arr[i + 2] << endl;
                cout << "组成最大三角形的三条边是" << arr[i] << "," << arr[i + 1] << "," << arr[i + 2] << endl;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findBiggestPerimeterTriangle(n, arr);

    system("pause");
    return 0;
}