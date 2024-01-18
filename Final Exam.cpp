#include <iostream>
#include <vector>
using namespace std;

struct BSTNode
{
    int val;
    BSTNode *left, *right;
    BSTNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

BSTNode* buildTree(vector<int>& preOrder, int& index) {
    if (index >= preOrder.size() || preOrder[index] == 0) {
        if (preOrder[index] == 0) {
            ++index;
        }
        return nullptr;
    }
    BSTNode* root = new BSTNode(preOrder[index]);
    root->left = buildTree(preOrder, index);
    root->right = buildTree(preOrder, index);
    return root;
}

int searchNum(BSTNode* root, int x) {
    if (root == nullptr) return 0;
    if (x == root->val) return 1;
    else if (x < root->val) return searchNum(root->left, x);
    else return searchNum(root->right, x);
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> preOrder(n);
    for (int i = 0; i < n; ++i) {
        cin >> preOrder[i];
    }
    int index = 0;
    BSTNode* root = buildTree(preOrder, index);
    for (int j = 0; j < m; ++j) {
        int x;
        cin >> x;
        int count = searchNum(root, x);
        cout << count << endl;
    }

    system("pause");
    return 0;
}