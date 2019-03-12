#include<iostream>
#include <stdlib.h>

using namespace std;

void genarray(int * A, int n)
{
  // Generates an array of random integers and size n
  for(int i = 0; i < n; i++)
    {
      int a = rand();
      A[i] = a % 1000;
    }
  return;
}

void printarray(int * A, int n)
{
  for(int i = 0; i < n; i++)
    {
      cout << A[i] << "   " ;
    }
  cout << endl;
  return;
}

void heapify(int * A, int n, int i)
{
  if(n <= 0) return;
  while (i<=n)
    {
      int L = 2*i + 1; int R = 2*i + 2, m;
      if(L >= n) break;
      if(L == n-1) m = L;
      else m = (A[L] >= A[R])? L : R;
      if(A[i] > A[m]) break;
      else
	{
	  A[i] = A[i] + A[m];
	  A[m] = A[i] - A[m];
	  A[i] = A[i] - A[m];
	}
      i = m;
    }
  return;
}

void make_heap(int * A, int n)
{
  for(int i = n/2; i >= 0; i--)
    {
      heapify(A, n, i);
    }
  return;
}

void insert(int * A, int n, int x)
{
  // n is the current size of the array
  A[n] = x;
  int i = n;
  while(i > 0)
    {
      int p = int(i/2);
      if(A[p] > A[i]) break;
      int t = A[p];
      A[p] = A[i];
      A[i] = t;
      i = p;
    }
}



int main()
{
  cout << "Enter the number of array elements:";
  int n;
  cin >> n;
  int A[1000];
  genarray(A, n);
  printarray(A, n);
  make_heap(A, n);
  printarray(A, n);
  int x = 0;
  while(1)
    {
      cin >> x;
      if(x == -1) break;
      insert(A, n, x);
      n++;
      make_heap(A, n);
      printarray(A, n);
    }
  
  return 0;
}
