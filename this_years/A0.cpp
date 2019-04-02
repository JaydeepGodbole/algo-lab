#include<iostream>

using namespace std;

struct node
{
  int x;
  node* next1;
  node* next2;
};

node * createlist1(int n, int a)
{
  node * A;
  node * temp;
  for(int i = 0; i < n/a; i++)
    {
      if(i == 0)
	{
	  A = new node;
	  A -> x = a;
	  A -> next2 = NULL;
	  A -> next1 = NULL;
	  temp = A;
	}
      else
	{
	  temp -> next1 = new node;
	  temp = temp -> next1;
	  temp -> x = (i+1)*a;
	  temp -> next1 = NULL;
	  temp -> next2 = NULL;
	}
    }
  return A;
}

node * createlist2(int n, int b, node * A, int a)
{
  cout << "entered2" << endl;
  node * B;
  node * list1 = A;
  node * temp;
  for(int i = 0; i < n/b; i++)
    {
      cout << i << endl;
      while((list1 -> x % b != 0) && list1 != NULL)
	{
	  cout << "While" << endl;
	  list1 = list1 -> next1;
	}
      if(i == 0)
	{
	  cout << "I = 0" << endl;
	  if(b == a)
	    {
	      B = A;
	      list1 = list1 -> next1;
	    }
	  else
	    {
	      B = new node;
	      B -> x = b;
	      B -> next1 = NULL;
	      B -> next2 = NULL;
	    }
	  temp = B;
	  cout << "exit else" << endl;
	}
      else
	{
	  if((i+1)*b % a == 0)
	    {
	      temp -> next2 = list1;
	      list1 = list1 -> next1;
	    }
	  else
	    {
	      temp = new node;
	      temp -> x = (i+1)*b;
	      temp -> next1 = NULL;
	      temp -> next2 = NULL;
	    }
	  temp = temp -> next2;
	}
    }
  
  return B;
}

void prnlist(node * A, int x)
{
  node * t = A;
  while(t != NULL)
    {
      cout << t -> x << " ";
      if(x == 1) t = t -> next1;
      else t = t -> next2;
    }
  cout << endl;
}


int main()
{
  int n,a,b;
  cout << "n = ";
  cin >> n;
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
  node * A = createlist1(n, a);
  node * B = createlist2(n, b, A, a);
  prnlist(A, 1);
  //prnlist(B, 2);
  //  prnboth(A, B);

  return 0;
}
 
