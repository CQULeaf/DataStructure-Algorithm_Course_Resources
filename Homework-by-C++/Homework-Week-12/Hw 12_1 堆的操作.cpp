#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printHeap(vector<int>& heap) {
    for (int i = 1; i < heap.size(); ++i)
        cout << heap[i] << (i < heap.size() - 1 ? " " : "");
    cout << endl;
}

void siftUp(int i, vector<int>& heap) {
    int temp = heap[i];
    while (i > 1 && temp < heap[i / 2]) {
        heap[i] = heap[i / 2];
        i = i / 2;
    }
    heap[i] = temp;
}

void siftDown(int i, vector<int>& heap) {
    int temp = heap[i];
    int size = heap.size();
    while (2 * i < size) {
        int child = 2 * i;
        if (child + 1 < size && heap[child] > heap[child + 1]) {
            child++;
        }
        if (temp <= heap[child]) {
            break;
        }
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = temp;    
}

void insert(int value, vector<int>& heap) {
    heap.push_back(value);
    siftUp(heap.size() - 1, heap);
}

void deleteMin(vector<int>& heap) {
    if (heap.size() > 1) {
        heap[1] = heap.back();
        heap.pop_back();
        siftDown(1, heap);
    }
}

void buildHeap(vector<int>& heap) {
    int n = heap.size() - 1;
    for (int i = n / 2; i >= 1; --i) {
        siftDown(i, heap);
    }
}

int main() {
    int N, K, x;
    cin >> N >> K;
    vector<int> heap = {0};
    for (int i = 0; i < K; ++i) {
        int operation;
        cin >> operation;
        if (operation == 1) {
            cin >> x;
            insert(x, heap);
        } else if (operation == -1) {
            deleteMin(heap);
        }
        printHeap(heap);
    }

    int M;
    cin >> M;
    vector<int> elements(M + 1, 0);
    for (int i = 1; i < M + 1; ++i) {
        cin >> elements[i];
    }
    buildHeap(elements);
    printHeap(elements);

    system("pause");
    return 0;
}