#include<iostream>

using namespace std;

void greedy(float ** EF, int ** PP, int n)
{
  int i = 0;
  int j = 0;
  float energy = 1.0;
  while((i < n) && (j < n))
    {
      if(i == n-1)
	{
	  while(j < n-1)
	    {
	      cout << "At (" << i << "," << j <<") with energy level =" << energy << endl;
	      energy *= (PP[i][j]) ? 1.25 : 1;
	      j = j+1;
	    }
	  cout << "At (" << i << "," << j <<") with energy level =" << energy << endl;
	  break;
	}
      else if(j == n-1)
	{
	  while(i < n-1)
	    {
	      cout << "At (" << i << "," << j <<") with energy level =" << energy << endl;
	      energy *= EF[i][j];
	      i = i+1;
	    }
	  cout << "At (" << i << "," << j <<") with energy level =" << energy << endl;
	  break;
	}
      else
	{
	  cout << "At (" << i << "," << j <<") with energy level =" << energy << endl;
	  int max = j;
	  float maxe = energy;
	  float tempe = energy;
	  for(int k = j; k < n; k++)
	    {
	      tempe = tempe * EF[i][k];
	      if(tempe > maxe)
		{
		  maxe = tempe;
		  max = k;
		}
	      tempe *= (PP[i][k])? 1.25 : 1;
	    }
	  i++;
	  j = max;
	  energy = maxe;
	}
      
    }
}

int main()
{
  int n;
  cout << "n = ";
  cin >> n;
  cout << endl << "+++ Exhausting factors:" << endl;
  float **EF = new float*[n-1];
  for(int i = 0; i < n-1; i++)
    {
      cout << "    " ;
      EF[i] = new float[n];
      for(int j = 0; j < n; j++)
	{
	  cin >> EF[i][j];
	}
      cout << endl;
    }
  cout << endl << "+++ Potion positions:" << endl;
  int **PP = new int*[n];
  for(int i = 0; i < n; i++)
    {
      cout << "    " ;
      PP[i] = new int[n-1];
      for(int j = 0; j < n-1; j++)
	{
	  cin >> PP[i][j];
	}
      cout << endl;
    }
  greedy(EF, PP, n);
  //DP(EF, PP, n);
  //DPsol(EF, PP, n);
  
  return 0;
}
