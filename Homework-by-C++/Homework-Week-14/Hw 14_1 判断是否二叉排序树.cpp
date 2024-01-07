#include <iostream>
#include <string>
#include <climits>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const string &preorder, int &index) {
    if (index >= preorder.size() || preorder[index] == '*') {
        ++index; // Skip the '*' character
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[index++] - '0');
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);
    return root;
}

void inOrderHelper(TreeNode* node, vector<int> &result) {
    if (node != nullptr) {
        inOrderHelper(node->left, result);  
        result.push_back(node->val);        
        inOrderHelper(node->right, result); 
    }
}

vector<int> inOrderTree(TreeNode* root) {
    vector<int> result;
    inOrderHelper(root, result);
    return result;
}

bool isBST(const vector<int>& result) {
    for (int i = 1; i < result.size(); ++i) {
        if (result[i] <= result[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string preorder;
    while (cin >> preorder) {
        int index = 0;
        TreeNode* root = buildTree(preorder, index);
        vector<int> result = inOrderTree(root);
        cout << (isBST(result) ? "YES" : "NO") << endl;
    }

    system("pause");
    return 0;
}