#include <iostream>
using namespace std;

// 定义元素类型，这里假设元素类型为int
typedef int ElemType;

// 定义链表的节点
struct ListNode {
    ElemType data;  // 数据域
    ListNode* next; // 指针域，指向下一个节点
};

// 定义链表
struct LinkList {
    ListNode* head; // 指向链表的头节点
    int length;     // 链表的长度

    // 构造函数
    LinkList() : head(nullptr), length(0) {}

    // 初始化链表
    void InitList() {
        head = new ListNode(); // 创建头节点
        head->next = nullptr; // 初始化为空链表
        length = 0;
    }

    // 销毁链表
    void DestroyList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        length = 0;
    }

    // 清空链表
    void Clear() {
        DestroyList();
        InitList();
    }

    // 判断链表是否为空
    bool IsEmpty() const {
        return length == 0;
    }

    // 获取链表的长度
    int Length() const {
        return length;
    }

    // 获取链表第i个位置的元素
    bool Get(int i, ElemType& e) {
        if (i < 1 || i > length) return false; // 检查索引有效性
        ListNode* current = head->next;        // 从第1个元素开始
        for (int k = 1; k < i; ++k) {          // 移动到第i个元素
            current = current->next;
        }
        e = current->data;                     // 获取数据
        return true;
    }

    // 在链表第i个位置插入新元素
    bool Insert(int i, ElemType e) {
        if (i < 1 || i > length + 1) return false; // 检查索引有效性
        ListNode* current = head;
        for (int k = 1; k < i; ++k) {              // 移动到第i个元素的前驱
            current = current->next;
        }
        ListNode* newNode = new ListNode();        // 创建新节点
        newNode->data = e;                         
        newNode->next = current->next;             
        current->next = newNode;                   
        length++;
        return true;
    }

    // 删除链表第i个位置的元素
    bool Remove(int i) {
        if (i < 1 || i > length) return false; // 检查索引有效性
        ListNode* current = head;
        for (int k = 1; k < i; ++k) {          // 移动到第i个元素的前驱
            current = current->next;
        }
        ListNode* toDelete = current->next;    // 找到要删除的节点
        current->next = toDelete->next;        
        delete toDelete;                       
        length--;
        return true;
    }
};

int main() {
    LinkList list; // 创建链表对象
    list.InitList(); // 初始化链表

    // 插入元素
    list.Insert(1, 10); 
    list.Insert(2, 20); 

    int element;
    if(list.Get(2, element)) {
        cout << "Element at position 2 is: " << element << endl;
    }

    list.DestroyList(); // 销毁链表

    system("pause");
    return 0;
}
