#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

vector<int> heap;
map<int, int> positionMap;

void up(int idx) {
    while (idx > 1 && heap[idx] < heap[idx / 2]) {
        swap(heap[idx], heap[idx / 2]);
        positionMap[heap[idx]] = idx;
        positionMap[heap[idx / 2]] = idx / 2;
        idx /= 2;
    }
}

bool isRoot(int x) {
    return positionMap[x] == 1;
}

bool isParentOf(int x, int y) {
    return positionMap[x] == positionMap[y] / 2;
}

bool isChildOf(int x, int y) {
    return positionMap[y] == positionMap[x] / 2;
}

bool areSiblings(int x, int y) {
    return positionMap[x] / 2 == positionMap[y] / 2;
}

int main() {
    int n, m;
    cin >> n >> m;
    heap.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> heap[i];
        positionMap[heap[i]] = i;
        up(i);
    }

    while (m--) {
        int x;
        string rel, temp;
        cin >> x >> rel;
        if (rel == "is") {
            cin >> temp;
            if (temp == "the") {
                cin >> temp;
                if (temp == "root") {
                    cout << (isRoot(x) ? "T" : "F") << endl;
                } else { // "parent"
                    cin >> temp; 
                    int y;
                    cin >> y;
                    cout << (isParentOf(x, y) ? "T" : "F") << endl;
                }
            } else { // "a" child
                cin >> temp >> temp; 
                int y;
                cin >> y;
                cout << (isChildOf(x, y) ? "T" : "F") << endl;
            }
        } else { // "and"
            int y;
            cin >> y >> temp >> temp; 
            cout << (areSiblings(x, y) ? "T" : "F") << endl;
        }
    }

    return 0;
}