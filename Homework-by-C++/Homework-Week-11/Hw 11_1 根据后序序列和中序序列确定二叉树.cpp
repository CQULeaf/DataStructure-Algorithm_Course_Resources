#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeHelper(vector<int>& postOrder, int pStart, int pEnd, vector<int>& inOrder, int iStart, int iEnd, unordered_map<int, int>& inMap) {
    if (pStart > pEnd || iStart > iEnd) return nullptr;
    TreeNode* root = new TreeNode(postOrder[pEnd]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - iStart;

    root->left = buildTreeHelper(postOrder, pStart, pStart + numsLeft - 1, inOrder, iStart, inRoot - 1, inMap);
    root->right = buildTreeHelper(postOrder, pStart + numsLeft, pEnd - 1, inOrder, inRoot + 1, iEnd, inMap);
    return root;
}

TreeNode* buildTree(vector<int>& postOrder, vector<int>& inOrder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inOrder.size(); ++i) {
        inMap[inOrder[i]] = i;
    }
    return buildTreeHelper(postOrder, 0, postOrder.size() - 1, inOrder, 0, inOrder.size() - 1, inMap);
}

void printTreePreOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << " " << root->val;
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}

int height(TreeNode* root) {
    if (root == nullptr) return 0;
    else return 1 + max(height(root->left), height(root->right));
}

int main() {
    int n;
    cin >> n;
    vector<int> postOrder(n);
    vector<int> inOrder(n);
    for (int i = 0; i < n; ++i) {
        cin >> postOrder[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> inOrder[j];
    }

    TreeNode* root = buildTree(postOrder, inOrder);
    int level = height(root);
    cout << level;
    printTreePreOrder(root);
    cout << endl;

    system("pause");
    return 0;
}