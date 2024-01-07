#include <iostream>
#include <vector>
using namespace std;

long long calculateArea(int x, const vector<vector<int>>& oasis) {
    long long area = 0;
    for (const auto& o : oasis) {
        if (o[0] < x) {
            area += static_cast<long long>(min(x - o[0], o[2])) * static_cast<long long>(o[3]);
        }
    }
    return area;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> oasis(n, vector<int>(4));
    long long total_area = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> oasis[i][j];
        }
        total_area += static_cast<long long>(oasis[i][2]) * static_cast<long long>(oasis[i][3]);
    }

    int left = 0, right = 1000000;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (calculateArea(mid, oasis) * 2 < total_area) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    cout << left << endl;

    system("pause");
    return 0;
}