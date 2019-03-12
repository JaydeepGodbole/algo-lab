#include<iostream>

using namespace std;

struct node
{
  int key;
  node * left;
  node * right;
};

//Insert function adds an integer key into an already formed BST 
node * insert(node * T, int x)
{
  if(T == NULL)
    {
      T = new node;
      T -> key = x;
      T -> left = NULL;
      T -> right = NULL;
      return T;
    }
  node * p = T; node * q = NULL;
  while(p!= NULL)
    {
      if(p->key == x) return T;
      q = p;
      if(p -> key > x) p = p->left;
      else p = p->right;
    }
  p = new node;
  p->key = x;
  p->left = NULL;
  p->right = NULL;
  if(q->key < x) q->right = p;
  else q->left = p;
  return T;
}

// Takes an array of size n as input and returns a BST out of it
node * buildBST(int * A, int n)
{
  node * T;
  for(int i = 0 ; i<n ; i++)
    {
      T = insert(T, A[i]);
    }
  return T;
}

bool search(node * T, int x)
{
  if(T == NULL) return false;
  node * p = T;
  while(p != NULL)
    {
      if(p -> key == x) return true;
      else if(p -> key < x) p = p->right;
      else p = p->left;
    }
  return false;
}

int main()
{
  
  return 0;
}
