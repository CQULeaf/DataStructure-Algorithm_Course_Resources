#include <iostream>

using namespace std;

struct ListNode {
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
};

// 插入新节点
void InsertNode(ListNode*& head, ListNode*& tail, ListNode* position, int value) {
    ListNode* newNode = new ListNode(value);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        // 如果链表为空，新节点成为头节点和尾节点
    } else if (position == nullptr) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        // 如果指定位置为空，将新节点插入到链表头部
    } else {
        newNode->next = position->next;
        newNode->prev = position;
        // 在指定位置之后插入新节点
        if (position->next != nullptr) {
            position->next->prev = newNode;
        }
        position->next = newNode;

        // 如果在尾部插入，更新尾节点
        if (position == tail)
        {
            tail = newNode;
        }
    }

}

// 删除旧节点
void DeleteNode(ListNode*& head, ListNode*& tail, ListNode* node) {
    if (node == nullptr) return;

    if (node->prev != nullptr) {
        node->prev->next = node->next;
    } else {
        head = node->next;
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    } else {
        tail = node->prev;
    }

    delete node;
}

void PrintList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main(){
    cout << "请输入双向链表元素，输入-1结束: ";
    int value;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while (cin >> value)
    {
        if (value == -1){
            break;
        }
        if (head == nullptr){
            head = new ListNode(value);
            tail = head;
        } else {
            InsertNode(head, tail, tail, value);
        }
    }

    cout << "当前双向链表：";
    PrintList(head);
    
    InsertNode(head, tail, head->next, 9);
    cout << "当前双向链表：";
    PrintList(head);

    DeleteNode(head, tail, tail->prev);
    cout << "当前双向链表：";
    PrintList(head);

    system("pause");
    return 0;
}

