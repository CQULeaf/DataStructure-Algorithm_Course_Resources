#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left, * right;
    TreeNode(int value, TreeNode* leftTree = nullptr, TreeNode* rightTree = nullptr) :
        val(value), left(leftTree), right(rightTree) {}
};

bool isOddEvenTree(TreeNode* node, int level) {
    if (!node) return true;
    if ((node->val % 2) == (level % 2)) return true;
    return isOddEvenTree(node->left, level + 1) && isOddEvenTree(node->right, level + 1);
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
    bool result = isOddEvenTree(root, 1);
    if (result) {
        cout << "这是一个奇偶树。" << endl;
    } else {
        cout << "这不是一个奇偶树。" << endl;
    }

    system("pause");
    return 0;
}