#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;
void print(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
}

int main() 
{
	int n, m, p; cin >> n >> m >> p;
	int sum = 0;
	vector<int>arr(m);
	vector<bool>judge(m, true);
	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		int count = 1;
		int index = num % p;
		if (judge[index])
		{
			arr[index] = num;
			sum += count;
			judge[index] = false;
		}
		else
		{
			while (!judge[index])
			{
				index=(index+1)%m;
				count++;
			}
			arr[index] = num;
			sum += count;
			judge[index] = false;
		}

	}
	cout << sum << '/' << n << endl;
	int sum1 = 0;
	for (int i = 0; i < p; i++)
	{
		int count = 1; int j = i;
		while (!judge[j])
		{
			count++;
			j = (j + 1) % m;
		}
			
		sum1 += count;

	}
	cout << sum1<<'/'<<p;

    system("pause");
	return 0;
}