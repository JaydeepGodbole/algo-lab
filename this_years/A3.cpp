#include<iostream>
#include<cstdlib>

using namespace std;

void genarrays(int * P, float * R, int n)
{
  for(int i = 0; i < n; i++)
    {
      P[i] = rand()%1000;
      R[i] = 1 + rand()%2 + rand()%10000/10000.0;
    }
  return;
}

void printarrays(int * P, float * R, int n)
{
  cout << "P: ";
  for(int i = 0; i < n; i++)
    {
      cout << P[i] << " ";
    }
  cout << endl;
  cout << "R: ";
  for(int i = 0; i < n; i++)
    {
      cout << R[i] << " ";
    }
  cout << endl;
}

void merge(float * A, int a, float * B, int b)
{
  float * q = new float[a+b+2];
  int count1 = 0; int count2 = 0;
  while((count1<=a)&&(count2<=b))
    {
      if(A[count1 
    }
}

void mergesort(float * A, int n)
{
  // n is the index, so sort from 0 to n
  if(n <= 0) return;
  mergesort(A, n/2);
  mergesort(A + n/2 + 1, n - n/2 - 1);
  merge(A, n/2, A + n/2 + 1, n - n/2 - 1);
}

int main()
{
  cout << "n = ";
  int n;
  cin >> n;
  int * P; float * R;
  P = new int[n];
  R = new float[n];
  genarrays(P, R, n);
  printarrays(P, R, n);

  return 0;
}
