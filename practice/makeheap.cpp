#include <iostream>
#include <stdlib.h>

using namespace std;

void heapify(int * H, int size, int i)
{
	int L, R, max, t;
	while(1)
	{
		L = 2*i + 1; R = L + 1;
		if(L >= size) return;
		max = ((R == size) || (H[L] > H[R])) ? L : R;
		if(H[max] < H[i]) return;
		t = H[max];
		H[max] = H[i];
		H[i] = t;
		i = max;
	}
}

void makeheap(int * H, int size)
{
	int i;
	for(i = size/2 - 1; i >= 0; i--) heapify(H, size, i);
	return;
}

void printarray(int * p, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	return ;
}

int main()
{
	cout << "Enter the size of the array:";
	int size;
	cin >> size;
	int * p = new int[size];
	for(int i = 0; i < size; i++)
	{
		p[i] = rand() % 10000;
	}
	printarray(p, size);
	makeheap(p, size);
	printarray(p, size);

	return 0;
}