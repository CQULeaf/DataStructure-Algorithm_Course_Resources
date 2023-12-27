#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        // Custom comparator for the priority queue
        auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first || (a.first == b.first && a.second > b.second);
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare); // min heap

        // Push the head of each list into the priority queue
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                pq.emplace(lists[i]->val, i);
                lists[i] = lists[i]->next;
            }
        }

        while (!pq.empty()) {
            auto [val, idx] = pq.top(); // structured bindings (C++17 feature)
            pq.pop();
            current->next = new ListNode(val);
            current = current->next;

            if (lists[idx]) {
                pq.emplace(lists[idx]->val, idx);
                lists[idx] = lists[idx]->next;
            }
        }

        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};