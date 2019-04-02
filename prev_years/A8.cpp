#include<iostream>

using namespace std;

struct node
{
  int vertex;
  node* next;
};

struct Graph
{
  int numVertices;
  node ** adjLists;
};

node * createnode(int v)
{
  node * t = new node;
  t->vertex = v;
  t->next = NULL;
  return t;
}

Graph * creategraph(int numv)
{
  Graph * graph = new Graph;
  graph -> numVertices = numv;
  graph -> adjLists = new node*[numv];
  for(int i = 0; i < numv; i++)
    {
      graph -> adjLists[i] = NULL;
    }
  return graph;
}

void addedge(Graph * g, int v1, int v2)
{
  node * t = createnode(v2);
  t->next = g->adjLists[v1];
  g->adjLists[v1] = t;
  
  t = createnode(v1);
  t->next = g->adjLists[v2];
  g->adjLists[v2] = t;
}

void printgraph(Graph * g)
{
  for(int i = 0; i < g->numVertices; i++)
    {
      node * t = g->adjLists[i];
      cout << i;
      while(t!=NULL)
	{
	  cout << " -> " << t->vertex;
	  t = t->next;
	}
      cout << endl;
    }
}

int main()
{
  int n,m;
  cout << "n = ";
  cin >> n;
  cout << "m = ";
  cin >> m;
  
  Graph * graph = creategraph(m);
  
  cout << "Enter the pairs of points that you want to be connected" << endl;
  int v1 = 0; int v2 = 0;
  while(!((v1 < 0) || (v1 >= m) || (v2 < 0) || (v2 > =m)))
    {
      cin >> v1 >> v2;
      
    }
  return 0;
}
