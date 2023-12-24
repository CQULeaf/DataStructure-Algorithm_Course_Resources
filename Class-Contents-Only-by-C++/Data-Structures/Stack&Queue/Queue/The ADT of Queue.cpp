#include <iostream>

using namespace std;

template<typename T, int MAX_SIZE>
class Queue {
private:
    T data[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    // 初始化一个空的队列
    Queue() : front(0), rear(0), count(0) {}

    // 销毁队列
    ~Queue() {}

    // 清空队列
    void Clear() {
        front = rear = count = 0;
    }

    // 检查队列是否为空
    bool IsEmpty() const {
        return count == 0;
    }

    // 检查队列是否已满
    bool IsFull() const {
        return count == MAX_SIZE;
    }

    // 返回队首元素
    T GetFront() const {
        if (IsEmpty()) {
            cout << "Queue is empty" << endl;
        }
        return data[front];
    }

    // 入队操作
    void EnQueue(const T& item) {
        if (IsFull()) {
            cout << "Queue is full" << endl;
        }
        data[rear] = item;
        rear = (rear + 1) % MAX_SIZE;
        count++;
    }

    // 出队操作
    void DeQueue() {
        if (IsEmpty()) {
            cout << "Queue is empty" << endl;
        }
        front = (front + 1) % MAX_SIZE;
        count--;
    }
};

int main() {
    Queue<int, 5> queue;

    queue.EnQueue(1);
    queue.EnQueue(2);
    queue.EnQueue(3);

    cout << "Front element: " << queue.GetFront() << endl;

    queue.DeQueue();
    cout << "Front element after dequeue: " << queue.GetFront() << endl;

    system("pause");
    return 0;
}
