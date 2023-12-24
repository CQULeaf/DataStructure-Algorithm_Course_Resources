#include <iostream>

using namespace std;

template<typename T>
class LinkedQueue {
private:
    struct Node {
        T data;
        Node* next;

        Node(T data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* front;
    Node* rear;

public:
    LinkedQueue() : front(nullptr), rear(nullptr) {}

    ~LinkedQueue() {
        while (front != nullptr) {
            Dequeue();
        }
    }

    void Enqueue(const T& item) {
        Node* node = new Node(item);
        if (IsEmpty()) {
            front = rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty" << endl;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    T Front() const {
        if (IsEmpty()) {
            cout << "Queue is empty" << endl;
        }
        return front->data;
    }

    bool IsEmpty() const {
        return front == nullptr;
    }
};

int main() {
    LinkedQueue<int> queue;

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);

    cout << "Front element: " << queue.Front() << endl;

    queue.Dequeue();
    cout << "Front element after dequeue: " << queue.Front() << endl;

    system("pause");
    return 0;
}
