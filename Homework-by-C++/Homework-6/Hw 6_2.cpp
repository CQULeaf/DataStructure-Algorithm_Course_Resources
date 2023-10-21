#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ball
{
    int number;
    int color;
};


int main()
{
/*
    ifstream infile("ball.in");
    int N;
    infile >> N;

    vector<Ball> balls(N);
    for(int i = 0; i < N; ++i)
    {
        infile >> balls[i].number >> balls[i].color;
    }
    infile.close();
*/

    int N;
    cin >> N;

    vector<Ball> balls(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> balls[i].number >> balls[i].color;
    }

    sort(balls.begin(), balls.end(), [](const Ball& a, const Ball& b)
        {return (a.number > b.number) || (a.number == b.number && a.color < b.color);});

    int redA = 0, greenA = 0, redB = 0, greenB = 0;
    for(int i = 0; i < N/2; ++i)
    {
        if(balls[i].color == 0) ++redA;
        else ++greenA;
    }
    for(int i = N/2; i < N; ++i)
    {
        if(balls[i].color == 0) ++redB;
        else ++greenB;
    }
/*
    ofstream outfile("ball.out");
    outfile << redA << " " << greenA << endl;
    outfile << redB << " " << greenB << endl;
    outfile.close();
*/
    cout << redA << " " << greenA << endl;
    cout << redB << " " << greenB << endl;
    
    return 0;
}