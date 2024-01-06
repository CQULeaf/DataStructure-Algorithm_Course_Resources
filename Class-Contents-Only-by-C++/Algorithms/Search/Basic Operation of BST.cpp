#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr || root->val == val) {
        return root;
    }
    return (val < root->val) ? searchBST(root->left, val) : searchBST(root->right, val);
}

TreeNode* searchBSTIterative(TreeNode* root, int val) {
    while (root != nullptr && root->val != val) {
        root = val < root->val ? root->left : root->right;
    }
    return root;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // 1. 无子节点
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // 2. 只有一个子节点
        else if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // 3. 有两个子节点
        else {
            TreeNode* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}

void preorderPrint(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->val << " ";
    preorderPrint(node->left);
    preorderPrint(node->right);
}

int main() {
    TreeNode* root = nullptr;

    // 插入节点
    root = insertIntoBST(root, 7);
    root = insertIntoBST(root, 4);
    root = insertIntoBST(root, 9);
    root = insertIntoBST(root, 2);
    root = insertIntoBST(root, 6);
    root = insertIntoBST(root, 8);
    root = insertIntoBST(root, 10);
    root = insertIntoBST(root, 1);
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 5);

    cout << "原始树的前序遍历: ";
    preorderPrint(root);
    cout << endl;

    root = deleteNode(root, 4);
    cout << "删除节点 4 后的前序遍历: ";
    preorderPrint(root);
    cout << endl;

    delete root;

    system("pause");
    return 0;
}