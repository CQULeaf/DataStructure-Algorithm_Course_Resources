#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student
{
    int id;
    int a;
    int b;
};

int main()
{
    int n;
    cin >> n;
    vector<student> students(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> students[i].id >> students[i].a >> students[i].b;
    }

    sort(students.begin(), students.end(), [](const student& x, const student& y)
    {return (x.a > y.a) || (x.a == y.a && x.b > y.b) || (x.a == y.a && x.b == y.b && x.id < y.id);});

    for(int i = 0; i < n; ++i)
    {
        cout << students[i].id << endl;
    }

    system("pause");
    return 0;
}
