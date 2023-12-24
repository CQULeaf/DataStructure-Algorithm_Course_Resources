#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Stack {
private:
    vector<T> elements;

public:
    // 初始化一个空的栈
    Stack() {}

    // 销毁栈
    ~Stack() {}

    // 清空栈
    void Clear() {
        elements.clear();
    }

    // 检查栈是否为空
    bool IsEmpty() const {
        return elements.empty();
    }

    // 检查栈是否已满（对于基于动态数组的实现，这个函数其实是不必要的）
    bool IsFull() const {
        return elements.size() == elements.max_size();
    }

    // 返回栈顶元素
    T Top() const {
        if (!IsEmpty()) {
            return elements.back();
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    // 入栈操作
    void Push(const T& item) {
        elements.push_back(item);
    }

    // 出栈操作
    void Pop() {
        if (!IsEmpty()) {
            elements.pop_back();
        } else {
            cout << "Stack is empty" << endl;
        }
    }
};

int main() {
    Stack<int> intStack;

    intStack.Push(10);
    intStack.Push(20);
    intStack.Push(30);

    cout << "The top element is: " << intStack.Top() << endl;

    intStack.Pop();
    cout << "After popping, the top element is: " << intStack.Top() << endl;

    system("pause");
    return 0;
}
