#include <iostream>

using namespace std;

template<typename T, int MAX_SIZE>
class SequentialStack {
private:
    T data[MAX_SIZE];  // 存储栈元素的数组
    int top;           // 栈顶索引

public:
    // 构造函数，初始化空栈
    SequentialStack() : top(-1) {}

    // 压栈操作
    void Push(const T& item) {
        if (IsFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        data[++top] = item;
    }

    // 出栈操作
    void Pop() {
        if (IsEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    // 读取栈顶元素
    T Top() const {
        if (IsEmpty()) {
            throw out_of_range("Stack is Empty");
        }
        return data[top];
    }

    // 检查栈是否为空
    bool IsEmpty() const {
        return top == -1;
    }

    // 检查栈是否已满
    bool IsFull() const {
        return top == MAX_SIZE - 1;
    }
};

int main() {
    SequentialStack<int, 5> stack;

    // 压栈操作
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    // 读取栈顶元素
    cout << "Top element: " << stack.Top() << endl;

    // 出栈操作
    stack.Pop();
    cout << "Top element after pop: " << stack.Top() << endl;

    // 尝试导致栈溢出
    for (int i = 0; i < 10; i++) {
        stack.Push(i);
    }

    system("pause");
    return 0;
}
