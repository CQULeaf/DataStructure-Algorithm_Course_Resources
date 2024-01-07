#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int calculateWPL(vector<int>& weights) {
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int weight : weights) {
        min_heap.push(weight);
    }

    int wpl = 0;
    while (min_heap.size() > 1) {
        int x = min_heap.top();
        min_heap.pop();
        int y = min_heap.top();
        min_heap.pop();

        int z = x + y;
        min_heap.push(z);

        wpl += z;        
    }

    return wpl;
}

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    int wpl = calculateWPL(weights);
    cout << wpl << endl;

    system("pause");
    return 0;
}