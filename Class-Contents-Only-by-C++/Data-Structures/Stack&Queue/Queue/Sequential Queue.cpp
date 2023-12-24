#include <iostream>

using namespace std;

template<typename T, int MAX_SIZE>
class SequentialQueue {
private:
    T data[MAX_SIZE];
    int front;
    int rear;

public:
    SequentialQueue() : front(0), rear(0) {}

    void Enqueue(const T& item) {
        if ((rear + 1) % MAX_SIZE == front) {
            cout << "Queue is full" << endl;
        }
        data[rear] = item;
        rear = (rear + 1) % MAX_SIZE;
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty" << endl;
        }
        front = (front + 1) % MAX_SIZE;
    }

    T Front() const {
        if (IsEmpty()) {
            cout << "Queue is empty" << endl;
        }
        return data[front];
    }

    bool IsEmpty() const {
        return front == rear;
    }

    bool IsFull() const {
        return (rear + 1) % MAX_SIZE == front;
    }
};

int main() {
    SequentialQueue<int, 5> queue;

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);

    cout << "Front element: " << queue.Front() << endl;

    queue.Dequeue();
    cout << "Front element after dequeue: " << queue.Front() << endl;

    system("pause");
    return 0;
}
