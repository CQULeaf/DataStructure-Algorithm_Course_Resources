#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val, TreeNode* leftTree = nullptr, TreeNode* rightTree = nullptr) 
        : value(val), left(leftTree), right(rightTree) {}
};

TreeNode* createBinaryTree(int value, TreeNode* leftTree = nullptr, TreeNode* rightTree = nullptr) {
    return new TreeNode(value, leftTree, rightTree);
}

bool isLeaf(TreeNode* node) {
    return node != nullptr && node->left == nullptr && node->right == nullptr;
}

int countLeaves(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    if (isLeaf(node)) {
        return 1;
    }
    return countLeaves(node->left) + countLeaves(node->right);
}

int height(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + max(height(node->left), height(node->right));
}

void preOrder(TreeNode* node) {
    if (node != nullptr) {
        cout << node->value << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TreeNode* node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->value << " ";
        inOrder(node->right);
    }
}

void postOrder(TreeNode* node) {
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->value << " ";
    }
}

void levelOrder(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->value << " ";
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}

int main() {
    // 创建一些节点
    TreeNode* leftChild = createBinaryTree(2);
    TreeNode* rightChild = createBinaryTree(3);
    TreeNode* root = createBinaryTree(1, leftChild, rightChild);

    // 检查是否为叶节点
    cout << "Is leaf: " << boolalpha << isLeaf(leftChild) << endl;

    // 计算叶子的个数
    cout << "Number of leaves: " << countLeaves(root) << endl;

    // 计算树的高度
    cout << "Height of tree: " << height(root) << endl;

    // 执行遍历
    cout << "PreOrder: ";
    preOrder(root);
    cout << endl;

    cout << "InOrder: ";
    inOrder(root);
    cout << endl;

    cout << "PostOrder: ";
    postOrder(root);
    cout << endl;

    cout << "LevelOrder: ";
    levelOrder(root);
    cout << endl;

    system("pause");
    return 0;
}
