/* Name: A*.cpp
   Creator: Jaydeep Godbole (jaydeepg@iitkgp.ac.in)
   Date: March 19, 2019
   Description: This is the code for the assignment on union disjoint sets
*/

#include<iostream>

using namespace std;

/* Name: initialize
   Input: n - a non-negative integer, pointer to array, pointer to the size array
   Output: Void
   Description: Initialises the array and size array
*/

void initialize(int * A, int * size, int n)
{
  for(int i = 0; i < n; i++)
    {
      A[i] = i;
      size[i] = 1;
    }
}

int root(int * A, int a)
{
  a = A[a];
  while(1)
    {
      if(a == A[a]) return a;
      a = A[a];
    }
}

bool find(int * A, int a, int b)
{
  int ra = root(A, a);
  int rb = root(A, b);
  if(ra == rb) return true;
  else return false;
}

void weighted_union(int a, int b, int * A, int * size)
{
  int ra = root(A, a);
  int rb = root(A, b);

  if(ra!=rb)
    {
      if(size[ra] < size[rb])
	{
	  A[ra] = rb;
	  size[rb] += size[ra];
	}
      else
	{
	  A[rb] = ra;
	  size[ra] += size[rb];
	}
    }
}

int main()
{
  cout << "n = " << endl;
  int n;
  cin>>n;
  int * A = new int[n];
  int * size = new int[n];
  initialize(A, size, n);
  
  int query=0;
  
  while(1)
    {
      cin >> query;
      if(query == 1)
	{
	  // find
	  int a,b;
	  cin >> a >> b;
	  if(find(A,a,b)) cout << "In a subset" << endl;
	  else cout << "Not in a subset" << endl;
	}
      else if(query == 2)
	{
	  // union
	  int a,b;
	  cin >> a >> b;
	  weighted_union(a, b, A, size);
	}
      else break;
    }
  
  return 0;
}
