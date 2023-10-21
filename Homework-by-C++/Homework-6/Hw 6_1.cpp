#include <iostream>

using namespace std;

void exchange(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void compare(int arr[], int i, int j, bool& exchanged)
{
    if(arr[i] > arr[j])
    {
        exchange(arr, i, j);
        exchanged = true;
    }
}

void display(int arr[], int N)
{
    for(int i = 0; i < N; i++)
    {
        if(i != N-1)
            cout << arr[i] << " ";
        else
            cout << arr[i];
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < N-1; i++)
    {
        bool exchanged = false;
        for(int j = 0; j < N-1-i; j++)
        {
            compare(arr, j , j+1, exchanged);
        }
        if(!exchanged)
            break;
        else
            display(arr, N);
    }

    system("pause");
    return 0;
}