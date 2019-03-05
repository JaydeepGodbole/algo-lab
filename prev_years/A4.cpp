#include<iostream>

struct _node {
struct _node *L; /* Left child pointer */
struct _node *R; /* Right child pointer */
struct _node *P; /* Parent pointer */
} treenode;

using namespace std;

void printspaces(int n)
{
  for(int i =0; i<n; i++)
    {
      cout << " ";
    }
  return;
}

void printtree(treenode head, int level)
{
  if (head == NULL)
    {
      cout << "|" ;
      return;
    }
  else
    {
      printspaces((level-1)*4);
      cout << "X\n" ;
      printspaces((level-1)*4);
      printtree(head.L, level+1);
      printspaces((level-1)*4);
      printtree(head.R, level+1);
      return;
    }
}

bool isleaf(treenode t)
{
  return ((t.L == NULL) && (t.R == NULL))? 1 : 0;
}

void destroytree(treenode head)
{
  if(head == NULL) return;
  if (isleaf(head)) free(head);
  destroytree(head.L);
  destroytree(head.R);
  return;
}

char* genenc1(treenode head, char* curr_enc)
{
  
