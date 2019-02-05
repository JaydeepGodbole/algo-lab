#include <iostream>
#include <stdlib.h>

using namespace std;

void printarray(int *p, int n)
{
  for(int i= 0; i < n; i++)
    {
      cout << p[i] << "\n";
    }
  cout << endl;
}

int max(int a, int b)
{
  return((a>b)?a : b);
}
void gencost(int * p, int n)
{
  for(int i = 0; i<n; i++)
    {
      p[i] = 100 + rand()%50;
    }
  return;
}

void genweights(int * p, int n)
{
  for(int i = 0; i<n; i++)
    {
      p[i] = 100 + rand()%20;
    }
  return;
}

void knapsack(int W, int * p, int * w, int n)
{
  int P[n+1][W+1];
  char Q[n+1][W+1];

  P[0][0] = 0;
  Q[0][0] = 's';

  for(int i = 0; i<=W; i++)
    {
      P[0][i] = -1000;
      Q[0][i] = 'v';
    }
  for(int i = 0; i <= n; i++)
    {
      for(int j = 0; j<=W; j++)
	{
	  if(j < w[i])
	    {
	      P[i][j] = P[i-1][j];
	      Q[i][j] = 'e';
	    }
	  else
	    {
	      P[i][j] = max(P[i-1][j], p[i-1] + P[i][j - w[i-1]]);
	      if(P[i][j] == -1000)
		{
		  Q[i][j] = 'v';
		}
	      else if (P[i][j]==P[i-1][j])
		{
		  Q[i][j] = 'e';
		}
	      else Q[i][j] = 'i';
	    }
	}
    }
  int max = 0;
  for(int i = 0; i<W; i++)
    {
      if(P[n][i] > P[n][max]) max = i;
    }
  cout << "Max profit is" << P[W][max] << endl;
  int i = n;
  int j = W;
  while(i>0)
    {
      if(Q[i][j] == 'i')
	{
	  cout << "Pack item no" << i << endl;
	  j-=w[i];
	}
      i--;
    }
}

int main()
{
  cout << "Enter the number of items" << endl;
  int n;
  cin >> n;
  int * p = new int[n];
  gencost(p, n);
  int * w = new int[n];
  genweights(w, n);
  printarray(p,n);
  printarray(w, n);
  cout << "Enter the max weight W";
  int W ;
  cin >> W;
  knapsack(W, p, w, n);

  return 0;
}
