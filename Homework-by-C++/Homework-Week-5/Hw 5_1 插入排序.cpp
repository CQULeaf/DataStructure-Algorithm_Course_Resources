#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for(int i = 1; i < N; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        for(int k = 0;k < N; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
    
    system("pause");
    return 0;
}

