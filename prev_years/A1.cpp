#include <iostream>
#include <stdlib.h>
#include <time.h>

#define N 100000000

using namespace std;

extern void registerme ( );
extern void startgame ( int );
extern int guess ( int );
extern void verifysoln ( int );

int playgame1()
{
  int i = 0;
  while(i <= N)
    {
      if(guess(i)) break;
      i++;
    }
  return i;
}

int playgame2()
{
  int i;
  while(!guess(i))
    {
      i = rand()%N;
    }
  return i;
}

int playgame3()
{
  int curr = 0;
  int prev = 0;
  int i = guess(curr);
  if(i == 1) return curr;
  else if(i == 0) return -1;
  while(1)
    {
      if(i == 1) return curr;
      else if(i == 2)
	{
	  if(curr >= prev)
	    {
	      prev = curr;
	      curr = (curr + N + 1)/2;
	    }
	  else
	    {
	      prev = curr;
	      curr = curr/2 + 1;
	    }
	}
      else if(i == 3)
	{
	  if(curr >= prev)
	    {
	      prev = curr;
	      curr = curr/2 + 1;
	    }
	  else
	    {
	      prev = curr;
	      curr = (curr + N + 1)/2;
	    }
	}
      i = guess(curr);
    }
  
}

int main()
{
  clock_t c1, c2;
  int a;
  registerme();
  startgame(1);
  c1 = clock();
  a = playgame1();
  c2 = clock();
  cout << "\n+++ Game 1\n a1 =" << a << " \n";
  cout << " Time taken = " <<  (double)(c2-c1)/(double)CLOCKS_PER_SEC <<  "sec\n";
  verifysoln(a);

  startgame(2);
  c1 = clock();
  a = playgame2();
  c2 = clock();
  cout << "\n+++ Game 2\n a1 =" << a << " \n";
  cout << " Time taken = " <<  (double)(c2-c1)/(double)CLOCKS_PER_SEC <<  "sec\n";
  verifysoln(a);

  startgame(3);
  c1 = clock();
  a = playgame3();
  c2 = clock();
  cout << "\n+++ Game 3\n a1 =" << a << " \n";
  cout << " Time taken = " <<  (double)(c2-c1)/(double)CLOCKS_PER_SEC <<  "sec\n";
  verifysoln(a);
  
  return 0;
}
