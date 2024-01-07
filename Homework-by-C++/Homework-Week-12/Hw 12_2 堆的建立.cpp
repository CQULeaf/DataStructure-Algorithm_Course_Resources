#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printHeap(const vector<int>& heap) {
    for (int i = 0; i < heap.size(); ++i) {
        cout << heap[i] << (i < heap.size() - 1 ? " " : "");
    }
    cout << endl;
}

void buildMaxHeap(vector<int> elements) {
    make_heap(elements.begin(), elements.end());
    printHeap(elements);
}

void buildMinHeap(vector<int> elements) {
    make_heap(elements.begin(), elements.end(), greater<int>());
    printHeap(elements);
}

int main() {
    int n;
    cin >> n;

    vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        cin >> elements[i];
    }

    buildMaxHeap(elements);
    buildMinHeap(elements);

    system("pause");
    return 0;
}