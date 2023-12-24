#include <iostream>

using namespace std;

template<typename T>
class LinkedStack {
private:
    struct Node {
        T data;
        Node* next;

        Node(T data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* top;  // 栈顶指针

public:
    LinkedStack() : top(nullptr) {}

    ~LinkedStack() {
        while (!IsEmpty()) {
            Pop();
        }
    }

    void Push(const T& item) {
        top = new Node(item, top);
    }

    void Pop() {
        if (IsEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* nodeToDelete = top;
        top = top->next;
        delete nodeToDelete;
    }

    T Top() const {
        if (IsEmpty()) {
            cout << "Stack is Empty" << endl;
        }
        return top->data;
    }

    bool IsEmpty() const {
        return top == nullptr;
    }
};

int main() {
    LinkedStack<int> stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    cout << "Top element: " << stack.Top() << endl;

    stack.Pop();
    cout << "Top element after pop: " << stack.Top() << endl;

    system("pause");
    return 0;
}
