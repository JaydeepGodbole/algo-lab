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

int knapsack(int W, int * p, int * w, int n)
{
  if(n==0||W<=0) return 0;
  if(w[n-1] > W) return knapsack(W, p, w, n-1);
  else return(max(p[n-1] + knapsack(W - w[n-1], p, w, n-1), knapsack(W, p, w, n-1)));
}

int main()
{
  cout << "Enter the number of the items";
  int n;
  cin >> n;
  int * p = new int[n];
  int * w = new int[n];
  cout << "Enter the prices of the items you just entered\n";
  gencost(p,n);
  printarray(p,n);
  cout << "Enter the weights of the items you just entered\n";
  genweights(w,n);
  printarray(w, n);
  cout << "Enter the max weight of the knapsacl"<< endl;
  int W ;
  cin >> W;
  cout << "Max price is = " << knapsack(W, p, w, n);
  
  return 0;
}
