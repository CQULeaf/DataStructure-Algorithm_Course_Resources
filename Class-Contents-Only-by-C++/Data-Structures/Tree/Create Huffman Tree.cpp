#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct HuffmanNode {
    int weight;
    HuffmanNode *left, *right;

    HuffmanNode(int w) : weight(w), left(nullptr), right(nullptr) {}

    // 重载比较运算符，优先队列需要
    bool operator>(const HuffmanNode& other) const {
        return weight > other.weight;
    }
};

HuffmanNode* createHuffmanTree(vector<int>& weights) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, greater<>> pq;

    for (int w : weights) {
        pq.push(new HuffmanNode(w));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        HuffmanNode* parent = new HuffmanNode(left->weight + right->weight);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    return pq.top();
}

void preOrderPrintHuffmanTree(HuffmanNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->weight << " ";
    preOrderPrintHuffmanTree(root->left);
    preOrderPrintHuffmanTree(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> weights(n);

    for(int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    HuffmanNode* root = createHuffmanTree(weights);

    preOrderPrintHuffmanTree(root);
    cout << endl;

    system("pause");
    return 0;
}