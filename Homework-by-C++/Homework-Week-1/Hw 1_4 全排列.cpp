#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void generate_permutations(vector<int>& arr, int n, vector<int>& curr_permutation) {
    if (curr_permutation.size() == n) {
        for (int i = 0; i < n; i++) {
            cout << curr_permutation[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
        return;
    }

    set<int> seen;
    for (int i = 0; i < arr.size(); i++) {
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
            curr_permutation.push_back(arr[i]);
            vector<int> next_arr = arr;
            next_arr.erase(next_arr.begin() + i);
            generate_permutations(next_arr, n, curr_permutation);
            curr_permutation.pop_back();
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    vector<int> curr_permutation;
    generate_permutations(arr, N, curr_permutation);

    system("pause");
    return 0;


}