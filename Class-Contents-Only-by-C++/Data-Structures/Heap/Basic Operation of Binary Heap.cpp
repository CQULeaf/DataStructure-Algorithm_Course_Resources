#include <iostream>
#include <vector>

using namespace std;

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
    while (2 * i <= size) {
        int child = 2 * i;
        if (child < size && heap[child] > heap[child + 1]) {
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
    // 创建一个空的二叉堆，第一个位置留空
    vector<int> heap = {0};

    insert(10, heap);
    insert(4, heap);
    insert(9, heap);
    insert(1, heap);
    insert(7, heap);

    cout << "堆中的元素（建堆后）: ";
    for (int i = 1; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    deleteMin(heap);

    cout << "删除最小元素后的堆: ";
    for (int i = 1; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;   
}