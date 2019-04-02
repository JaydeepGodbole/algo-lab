#include<iostream>

using namespace std;

extern void registerme ( );
extern void startgame ( int );
extern int valquery ( int );
extern int sgnquery ( int );
extern int delquery ( int );
extern int sumquery ( int );
extern void checksoln ( int, int );

void playgame0()
{
  startgame(0);
  int i,j;
  for(i = 0; i< 1000000000; i++)
    {
      if(valquery(i) != i)
  {
    j = valquery(i);
    break;
  }
    }
  int L,R;
  L = i;
  R = j;
  checksoln(L,R);
}

int callback(int start,int end, int mid)
{
  if((start > end)||(start < 0)||(end > 1000000000)) return -1;
  if(valquery(mid) == mid) return valquery(mid);
  if(callback(start,mid, (start + mid)/2) != -1) return callback(start,mid, (start + mid)/2);
  if(callback(mid, end, (mid + end/2)) != -1) return callback(mid, end, (mid + end)/2);
  return mid;
}

void playgame1()
{
  startgame(1);
  int L = 0,R = 0;
  int start = 0;
  int end = 999999999;
  L =  callback(start,end, (start + end)/2);
  R = valquery(L);
  checksoln(L,R);
}
void playgame2()
{
  startgame(2);
  int start, end, L, R, sign;
  int u = delquery(0);
  start = 0;
  end = 999999999;
  int mid = 0;
  int flag = 0;
  while(start < end)
    {
      cout << start << end << endl;
      mid = (start+end)/2;
      sign = sgnquery(mid);
      if(sign == -1)
  {
    start = mid + 1;
  }
      else if(sign == 1){ end = mid;}
      else if(sign == 0) 
  {
    flag = 1;
    break;
  }
    }
  mid = (start+end)/2;
  if(flag)
    {
      R = (2*mid + u)/2;
      L = (2*mid - u)/2;
    }
  else
    {
      R = (2*mid + u - 1)/2;
      L = (2*mid - u - 1)/2;
    }
  checksoln(L,R);
}

void playgame3()
{
  startgame(3);
  int least_cost, curr_cost, start=0, end,mid, L, R;
  end = sumquery(0)/2;
  cout << end << endl;
  curr_cost = sumquery(end);
  least_cost = curr_cost;
  cout << least_cost << endl;
  while(start < end)
    {
      mid = (start + end)/2;
      cout << start << "  " << end << endl;
      curr_cost = sumquery(mid);
      if(curr_cost > least_cost) start = mid + 1;
      else if(curr_cost ==  least_cost) end = mid;
    }
  mid = (start+end)/2;
  cout << mid << endl;
  L = mid;
  R = L + sumquery(mid);
  checksoln(L,R);
}


int main()
{
  registerme();
  playgame0();
  playgame1();
  playgame2();
  playgame3();

  return 0;
}

     
