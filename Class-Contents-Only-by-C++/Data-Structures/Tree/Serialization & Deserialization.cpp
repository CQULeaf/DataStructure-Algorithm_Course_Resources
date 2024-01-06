#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

string serialize(TreeNode* root) {
    if (root == nullptr) {
        return "#,";
    }
    return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
}

TreeNode* deserialize(stringstream& ss) {
    string val;
    getline(ss, val, ',');
    if (val == "#") 
        return nullptr;

    TreeNode* node = new TreeNode(stoi(val));
    node->left = deserialize(ss);
    node->right = deserialize(ss);
    return node;
}

TreeNode* deserialize(string data) {
    stringstream ss(data);
    return deserialize(ss);
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "EMPTY TREE!" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if (current == nullptr) {
            cout << "# ";
        } else {
            cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        }
    }
}

int main() {
    // 构建二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // 序列化
    string serialized = serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    // 反序列化
    TreeNode* deserialized = deserialize(serialized);
    cout << "Deserialized tree: ";
    printTree(deserialized);
    cout << endl;

    system("pause");
    return 0;

}