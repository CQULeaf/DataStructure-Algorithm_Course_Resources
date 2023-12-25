#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    int max_temp, min_temp;
    max_temp = min_temp = arr[0];

    for(int i = 1; i < N; ++i) {
        if(arr[i] > max_temp) {
            max_temp = arr[i];
        }
        if(arr[i] < min_temp) {
            min_temp = arr[i];
        }
    }

    cout << max_temp - min_temp << endl;
    
    system("pause");
    return 0;
}