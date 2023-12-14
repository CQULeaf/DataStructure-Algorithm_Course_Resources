#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
#include <cmath>

using namespace std;

void print(vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
        cout << arr[i] << " ";
    cout << arr[arr.size() - 1];

}

int main() 
{
    priority_queue<int>list;
    int n,m; cin >> n>>m;
    while (n--)
    {
        int num; cin >> num;
        list.push(num);
    }
    vector<int>arr;
    while (m--)
    {
        if (!list.empty())
        {
            arr.push_back(list.top());
            list.pop();
        }
    }
    print(arr);
    cout << endl;

    return 0;
}