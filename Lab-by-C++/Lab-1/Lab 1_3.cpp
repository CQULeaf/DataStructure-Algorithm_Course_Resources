#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

string can_exit(const vector<int>& entry_sequence, const vector<int>& exit_sequence)
{
    stack<int> s;
    int entry_pointer = 0;

    for(int car : exit_sequence)
    {
        while(s.empty() || s.top() != car)
        {
            if (entry_pointer >= entry_sequence.size())
                return "No";
            s.push(entry_sequence[entry_pointer]);
            entry_pointer++;
        }

        if(s.empty() || s.top() != car)
            return "No";
        else
            s.pop();
    }
    return "Yes";
}

int main()
{
    int T;
    cin >> T;
    vector<string> results;

    for(int t = 0; t < T; t++)
    {
        int n;
        cin >> n;
        
        vector<int> cars(2*n);
        for(int i = 0; i < 2*n; i++)
        {
            cin >> cars[i];
        }

        vector<int> entry_sequence(cars.begin(), cars.begin()+n);
        vector<int> exit_sequence(cars.begin() + n, cars.end());

        results.push_back(can_exit(entry_sequence, exit_sequence));      
    }

    for(const string& res : results)
    {
        cout << res << endl;
    }

    system("pause");
    return 0;
}