#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> calculate_averages(int n, const vector<int>& numbers) {
    priority_queue<int> max_heap; // Max-heap for the lower half
    priority_queue<int, vector<int>, greater<int>> min_heap; // Min-heap for the upper half

    vector<int> averages; // To store the result
    averages.reserve(n); // Reserve space for efficiency

    int current_min = numbers[0];
    int current_max = numbers[0];

    for (int number : numbers) {
        current_min = min(current_min, number);
        current_max = max(current_max, number);

        if (max_heap.empty() || number <= max_heap.top()) {
            max_heap.push(number);
        } else {
            min_heap.push(number);
        }

        // Balance the heaps if necessary
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        // Calculate the average based on the number of elements
        int average;
        if (max_heap.size() == min_heap.size()) {
            // Even number of elements
            int median1 = max_heap.top();
            int median2 = min_heap.top();
            average = (current_min + current_max + median1 + median2) / 4;
        } else {
            // Odd number of elements
            int median = max_heap.top();
            average = (current_min + current_max + median) / 3;
        }

        averages.push_back(average);
    }

    return averages;
}

int main() {
    ios_base::sync_with_stdio(false); // Speed up cin and cout
    cin.tie(nullptr); // Untie cin and cout

    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int& number : numbers) {
        cin >> number;
    }

    vector<int> averages = calculate_averages(n, numbers);

    for (size_t i = 0; i < averages.size(); ++i) {
        cout << averages[i];
        if (i < averages.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}
