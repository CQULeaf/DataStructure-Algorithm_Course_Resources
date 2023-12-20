#include <iostream>

using namespace std;

struct ListNode
{
    int data;
    ListNode* next;

    ListNode(int x) : data(x), next(nullptr) {}
};

ListNode* ReverseList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr){
        next = current->next; // 保存当前节点的下一个节点

        current->next = prev; // 将当前节点的next指向前一个节点

        prev = current; // 移动prev到当前节点
        current = next; // 移动current到下一节点
    }

    head = prev; // 更新头指针指向新的头节点
    return head;
}

void PrintList(ListNode* head){
    ListNode* current = head;
    while (current != nullptr){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    cout << "请输入链表元素，输入-1结束: ";
    int value;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* newHead = nullptr;

    while (cin >> value){
        if (value == -1){
            break;
        }

        ListNode* newNode = new ListNode(value);
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "显示当前链表" << endl;
    PrintList(head);

    newHead = ReverseList(head);
    cout << "显示翻转后的链表" << endl;
    PrintList(newHead);

    system("pause");
    return 0;
}