#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

// Next function generates random floating point numbers in an array of size n taken as parameter
float * genarray(int n)
{
	float * p = new float[n];
	for(int i = 0; i < n; i++)
	{
		p[i] = rand()%10000;
	}
	return p;
}

void printarray(float * p, int n)
{
	for ( int i = 0; i < n; i++)
	{
		cout << p[i] << endl;
	}
	cout << endl;
	return;
}

void quicksort (float *p, char c, int m, int n)
{
	if(m >= n) return;
	int pivot = m;
	for(int i = m + 1; i <= n; i++)
	{
		if((p[i] < p[pivot]) && (c == 'a'))
		{
			float temp = p[pivot];
			p[pivot] = p[i];
			p[i] = temp;
			pivot = i;
		}
		if((p[i] > p[pivot]) && (c == 'd'))
		{
			float temp = p[pivot];
			p[pivot] = p[i];
			p[i] = temp;
			pivot = i;
		}
	}

	quicksort(p, c, m, pivot - 1);
	quicksort(p, c, pivot + 1, n);
	return;
}

int main()
{
	cout << "Enter the size of the array" << endl;
	int n;
	cin >> n;
	float * p = genarray(n);
	printarray(p, n);
	quicksort(p, 'a', 0, n-1);
	cout << "now" << endl;
	printarray(p, n);

	return 0;
}