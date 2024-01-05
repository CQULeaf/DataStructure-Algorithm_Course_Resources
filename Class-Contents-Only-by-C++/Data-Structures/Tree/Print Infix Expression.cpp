#include <iostream>
using namespace std;

struct TreeNode 
{
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

void printInfixExpression(TreeNode* tree) {
    if (tree == nullptr) return;

    if (tree->left != nullptr) {
        cout << "(";
        printInfixExpression(tree->left);
        cout << ")";
    }

    cout << tree->data;

    if (tree->right != nullptr) {
        cout << "(";
        printInfixExpression(tree->right);
        cout << ")";
    }
}

void deleteTree(TreeNode* tree) {
    if (tree == nullptr) return;
    deleteTree(tree->left);
    deleteTree(tree->right);
    delete tree;
}

int main() {
    // 构建表达式树
    TreeNode* root = new TreeNode('+');
    root->left = new TreeNode('9');

    // 构建右子树
    TreeNode* right = new TreeNode('/');
    root->right = right;

    // 构建右子树的左部分 (6 + 3 * 2)
    TreeNode* rightLeft = new TreeNode('+');
    right->left = rightLeft;
    rightLeft->left = new TreeNode('6');
    TreeNode* rightLeftRight = new TreeNode('*');
    rightLeftRight->left = new TreeNode('3');
    rightLeftRight->right = new TreeNode('2');
    rightLeft->right = rightLeftRight;

    // 构建右子树的右部分 (8 / (5 - 3))
    TreeNode* rightRight = new TreeNode('/');
    right->right = rightRight;
    rightRight->left = new TreeNode('8');
    TreeNode* rightRightRight = new TreeNode('-');
    rightRightRight->left = new TreeNode('5');
    rightRightRight->right = new TreeNode('3');
    rightRight->right = rightRightRight;

    printInfixExpression(root);
    cout << endl;

// The output will be: (9)+(((6)+((3)*(2)))/((8)/((5)-(3))))

    deleteTree(root);

    system("pause");
    return 0;
}

