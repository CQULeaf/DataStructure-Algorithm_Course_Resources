#include <iostream>

using namespace std;

// 定义最大容量
const int MAX_SIZE = 100;

// 定义顺序表的结构体
template <typename ElemType>
struct SeqList {
    ElemType data[MAX_SIZE]; // 静态数组存储元素
    int length;              // 当前顺序表的长度

    // 构造函数
    SeqList() : length(0) {}

    // 初始化顺序表
    void InitList() {
        length = 0;
    }

    // 插入元素，位置i，元素值e
    bool Insert(int i, ElemType e) {
        if (length >= MAX_SIZE || i < 1 || i > length + 1) {
            return false;
        }
        for (int j = length; j >= i; j--) {
            data[j] = data[j - 1];
        }
        data[i - 1] = e;
        length++;
        return true;
    }

    // 删除元素，位置i
    bool Remove(int i) {
        if (i < 1 || i > length) {
            return false;
        }
        for (int j = i; j < length; j++) {
            data[j - 1] = data[j];
        }
        length--;
        return true;
    }

    // 获取元素，位置i
    bool Get(int i, ElemType &e) {
        if (i < 1 || i > length) {
            return false;
        }
        e = data[i - 1];
        return true;
    }

    // 打印顺序表所有元素
    void PrintList() {
        for (int i = 0; i < length; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    SeqList<int> list; // 创建顺序表实例
    list.InitList();   // 初始化顺序表

    // 测试插入
    list.Insert(1, 10); // 在位置1插入元素10
    list.Insert(2, 20); // 在位置2插入元素20
    list.PrintList();   // 打印顺序表

    // 测试删除
    list.Remove(1);    // 删除位置1的元素
    list.PrintList();  // 打印顺序表

    // 测试获取
    int elem;
    if (list.Get(1, elem)) {
        cout << "Element at position 1 is: " << elem << endl;
    } else {
        cout << "Get operation failed!" << endl;
    }

    // ...其他操作

    return 0;
}
