#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long calculate_profit(int N, vector<int>& prices) {
    priority_queue<int, vector<int>, greater<int>> min_heap;  // Min-heap to track the prices of stocks bought
    long long total_profit = 0;

    for (int i = 0; i < N; ++i) {
        // Buy a stock every day
        min_heap.push(prices[i]);

        // If it's not the last day, check if there are any stocks to sell
        if (i != N - 1) {
            while (!min_heap.empty() && min_heap.top() < prices[i + 1]) {
                total_profit += prices[i + 1] - min_heap.top();
                min_heap.pop();
            }
        } 
        // On the last day, sell all remaining stocks
        else {
            while (!min_heap.empty()) {
                total_profit += prices[i] - min_heap.top();
                min_heap.pop();
            }
        }
    }
    return total_profit;
}

int main() {
    int N;
    cin >> N;
    vector<int> prices(N);
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }

    cout << calculate_profit(N, prices) << endl;
    return 0;
}
