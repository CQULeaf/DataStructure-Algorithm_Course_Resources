#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<string, int> hash;

    for (int i = 0; i < n; i++) {
        string ID;
        int mile;
        cin >> ID >> mile;
        if (mile < k) {
            mile = k;
        }
        hash[ID] += mile;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string ID;
        cin >> ID;
        auto it = hash.find(ID);
        if (it != hash.end()) {
            cout << it->second << endl;
        } else {
            cout << "No Info" << endl;
        }
    }

    system("pause");
    return 0;
}