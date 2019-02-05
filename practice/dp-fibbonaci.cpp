#include<iostream>

using namespace std;

int main()
{
	cout << "Enter the number of the fibbonaci number you want to find\n";
	int n;
	cin >> n;
	if(n <= 0)
	{
		cout << "Enter sensible value of n you dumb fellow\n";
		return -1;
	}
	if (n == 1)
	{
		cout << "Number is 1\n";
		return 0;
	}
	else if(n == 2)
	{
		cout << "Number is 1\n";
		return 0;
	}
	int * p = new int[n];
	p[0] = 1;
	p[1] = 1;
	for(int i = 2; i<n; i++)
	{
		p[i] = p[i-1] + p[i-2];
	}
	cout << "Number is " << p[n-1] << endl;
	return 0;
}