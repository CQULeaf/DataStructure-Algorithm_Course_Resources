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
        }// 从最后一个元素开始，依次向后移动一个位置
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
        }// 从位置i开始，依次向前移动一个位置
        length--;
        return true;
    }

    // 获取元素，位置i
    bool Get(int i, ElemType e) {
        if (i < 1 || i > length) {
            return false;
        }
        e = data[i - 1];
        return true;
    }

    // 获取元素e的位置
    int Locate(ElemType e) {
        for (int i = 0; i < length; i++) {
            if (data[i] == e) {
                return i + 1;
            }
        }
        return 0;
    }

    // 翻转顺序表
    void Reverse() {
        for (int i = 0; i < length / 2; i++) {
            ElemType temp = data[i];
            data[i] = data[length - i - 1];
            data[length - i - 1] = temp;
        }
    }

    // 打印顺序表所有元素
    void PrintList() {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SeqList<int> list; // 创建顺序表实例
    list.InitList();   // 初始化顺序表

    // 测试插入
    list.Insert(1, 10); 
    list.Insert(2, 20); 
    list.Insert(3, 30); 
    list.Insert(4, 40); 
    list.PrintList();   

    // 测试删除
    list.Remove(1);    
    list.PrintList();  
    list.Remove(3);    
    list.PrintList();  

    // 测试翻转
    list.Reverse();    
    list.PrintList();  

    // 测试获取
    int elem;
    if (list.Get(1, elem)) {
        cout << "Element at position 1 is: " << elem << endl;
    } else {
        cout << "Get operation failed!" << endl;
    }

    // 测试定位
    int pos = list.Locate(30);
    if (pos != 0){
        cout << "Element 30 is located at " << pos << endl;
    }
    else {
        cout << "Element 30 is not found!" << endl;
    }

    system("pause");
    return 0;
}
