#include <iostream>

using namespace std;

int main()
{
	int * p = new int(10);
	for(int i = 0; i < 10; i++)
	{
		p[i] = i * 2;
	}
	cout << p[1] << endl;
	//(p + 10) = new int(2);
	cout << p[100] + 3;
	p[100] += 1;
	cout << p[100];
	return 0;
}