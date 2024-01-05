#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int value, TreeNode* leftTree = nullptr, TreeNode* rightTree = nullptr) : 
        val(value), left(leftTree), right(rightTree) {}
};

bool isOddEvenTree(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode*> nodes;
    queue<int> levels;
    nodes.push(root);
    levels.push(1);

    while (!nodes.empty()) {
        TreeNode* node = nodes.front();
        int level = levels.front();
        nodes.pop();
        levels.pop();

        if ((node->val % 2) == (level % 2)) return true;

        if (node->left) {
            nodes.push(node->left);
            levels.push(level + 1);
        }
        if (node->right) {
            nodes.push(node->right);
            levels.push(level + 1);
        }
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
        cout << "这是一个奇偶树。" << endl;
    } else {
        cout << "这不是一个奇偶树。" << endl;
    }

    system("pause");
    return 0;
}