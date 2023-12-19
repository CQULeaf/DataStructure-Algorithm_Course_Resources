#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;

    ListNode(int x) : data(x), next(nullptr) {}
};

ListNode* FindKthNodeFromBottom(ListNode* head, int k){
    if (head == nullptr || k <= 0){
        return nullptr;
    }

    ListNode* fast = head;
    ListNode* slow = head;

    // 移动fast指针，使其与slow指针之间相隔k个节点
    for (int i = 0; i < k; ++i){
        if (fast == nullptr){
            return nullptr;// 预防k超出链表长度这一情况
        }
        fast = fast->next;
    }

    // 同时移动fast和slow，直到fast到达链表末尾
    while (fast != nullptr){
        fast = fast->next;
        slow = slow->next;
    }

    return slow; // slow即为所求
}

void PrintList(ListNode* head){
    ListNode* current = head;
    while (current != nullptr){
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

    while (cin >> value) {
        if (value == -1){
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

    // 显示当前链表
    cout << "当前链表情况: ";
    PrintList(head);

    // 接受用户输入k值
    int k;
    cout << "你想要查找倒数第几个元素？";
    cin >> k;

    // 查找倒数第K个节点
    ListNode* result = FindKthNodeFromBottom(head, k);
    if (result != nullptr){
        cout << "你想查到的元素的值为：" << result->data << endl;
    }else {
        cout << "对不起，你想查找的元素不存在哦~" << endl;
    }

    // 收尾工作，清理链表内存
    while (head != nullptr){
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    system("pause");
    return 0;

}