#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isOddEvenTree(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode*> nodes;
    nodes.push(root);
    int level = 1;

    while (!nodes.empty()) {
        int size = nodes.size();
        int prev_value = INT_MIN;

        for (int i = 0; i < size; ++i) {
            TreeNode* node = nodes.front();
            nodes.pop();

            if ((node->val % 2) != (level % 2) || (node->val < prev_value))  return false;

            prev_value = node->val;

            if (node->left) nodes.push(node->left);
            if (node->right) nodes.push(node->right);
        }
        level++;
    }
    return true;
}

int main() {
    // 构建树
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    // 验证是否是奇偶树
    bool result = isOddEvenTree(root);
    if (result) {
        cout << "这是一个特殊奇偶树。" << endl;
    } else {
        cout << "这不是一个特殊奇偶树。" << endl;
    }

    system("pause");
    return 0;
}
