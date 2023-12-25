#include <iostream>
using namespace std;

int GCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int LCM(int a,int b) {
    return a * b / GCD(a, b);
} 

int main(){
    int A, B;
    cin >> A >> B;

    int gcd_result = GCD(A, B);
    int lcm_result = LCM(A, B);

    cout << gcd_result << "," << lcm_result << endl;

    system("pause");
    return 0;

}