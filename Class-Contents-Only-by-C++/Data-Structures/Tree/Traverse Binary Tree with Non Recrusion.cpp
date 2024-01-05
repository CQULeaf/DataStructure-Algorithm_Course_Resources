#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left, * right;
    TreeNode(int val, TreeNode* leftTree = nullptr, TreeNode* rightTree = nullptr) : value(val), left(leftTree), right(rightTree) {}
};

TreeNode* createBinaryTree(int value, TreeNode* left = nullptr, TreeNode* right = nullptr) {
    return new TreeNode(value, left, right);
}

void preOrderNonRecrusive(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        cout << node->value << " ";
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
}

void inOrderNonRecursive(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* current = root;
    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->value << " ";
        current = current->right;
    }
}

void postOrderNonRecursive(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->value << " ";
        s2.pop();
    }
}

int main() {
    // 创建一些节点
    TreeNode* left = createBinaryTree(2);
    TreeNode* right = createBinaryTree(3);
    TreeNode* root = createBinaryTree(1, left, right);

    // 执行遍历
    cout << "PreOrder: ";
    preOrderNonRecrusive(root);
    cout << endl;

    cout << "InOrder: ";
    inOrderNonRecursive(root);
    cout << endl;

    cout << "PostOrder: ";
    postOrderNonRecursive(root);
    cout << endl;

    system("pause");
    return 0;
}