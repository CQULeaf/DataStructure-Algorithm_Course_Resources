#include<iostream>
#include<vector>

using namespace std;

int main(){
    int numElements, hashSize;
    cin >> numElements >> hashSize;
    vector<int> hashTable(hashSize, -1);
    vector<int> result;

    for (int i = 0; i < numElements; i++) {
        int currentValue;
        cin >> currentValue;
        int index = currentValue % hashSize;

        if (hashTable[index] == -1) {
            hashTable[index] = currentValue;
            result.push_back(index);
        } else {
            int d = 0;
            int newIndex = index;

            while (hashTable[newIndex] != -1 && hashTable[newIndex] != currentValue) {
                d++;
                newIndex = (index + d) % hashSize;
            }

            hashTable[newIndex] = currentValue;
            result.push_back(newIndex);
        }
    }

    for (size_t i = 0; i < result.size() - 1; i++) {
        cout << result[i] << " ";
    }
    cout << result.back() << endl;

    system("pause");
    return 0;
}
