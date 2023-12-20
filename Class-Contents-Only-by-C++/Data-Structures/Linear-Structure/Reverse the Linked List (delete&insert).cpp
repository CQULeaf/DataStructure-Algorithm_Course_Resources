#include<iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;

    ListNode(int x) : data(x), next(nullptr) {}
};

ListNode* ReverseList(ListNode* head){
    ListNode* newHead = nullptr;
    ListNode* temp;

    while (head != nullptr)
    {
        temp = head; // 从原链表中删除头节点
        head = head->next; // 更新原链表中的头指针

        // 将temp节点插入到新链表的头部
        temp->next = newHead;
        newHead = temp;
    }
    
    return newHead;
}

void PrintList (ListNode* head){
    ListNode* current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

}

int main(){
    cout << "请输入链表元素，输入-1结束: ";
    int value;
    ListNode* head = nullptr;
    ListNode* bottom = nullptr;
    ListNode* newHead = nullptr;

    while (cin >> value){
        if (value == -1)
        {
            break;
        }

        ListNode* newNode = new ListNode(value);
        if (head == nullptr){
            head = newNode;
            bottom = newNode;
        }
        else{
            bottom->next = newNode;
            bottom = newNode;
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