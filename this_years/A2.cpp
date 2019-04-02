#include<iostream>
#include<math.h>

using namespace std;

extern void registerme ( int );
extern void startpart ( int );
extern void endpart ( int );
extern void makemove ( int , int , int );
extern void showpegs ( );

void ToH3(int i,int j,int p,int q,int r)
{
  if(i>j) return;  //error check condition
  if(i == j)       //base condition
    {
      makemove(i, p, q);
      return;
    }
  ToH3(i, j-1, p, r, q);  //move the top n-1 disks into the temp peg
  makemove(j, p, q);      //move the last disk
  ToH3(i, j-1, r, q, p);  //move the n-1 disks into the final peg
  return;
}

void ToH41(int i,int j,int p,int q,int r,int s)
{
  if(i>j) return;     //error check condition
  if(i == j)          //if n <= 3 do it directly
    {
      makemove(i, p, q);
      return;
    }
  if(j-i == 1)        //if n <= 3 do it directly
    {
      makemove(i, p, r);
      makemove(j, p, q);
      makemove(i, r, q);
      return;
    }
  if(j-i == 2)        //if n <= 3 do it directly
    {
      makemove(i, p, s);
      makemove(i+1, p, r);
      makemove(j, p, q);
      makemove(i+1, r, q);
      makemove(i, s, q);
      return;
    }
  int k = (j-i+1)/2;
  ToH41(i, j - k, p, s, q, r); //move the top 1 to n-k disks into the last peg
  ToH3(j-k+1,j,p,q,r);         //move the bottom k disks into the final peg using 3 pegs
  ToH41(i, j - k, s, q, p, r); //move the top 1 to n-k disks into the final peg
  return;
}

void ToH42(int i,int j,int p,int q,int r,int s, int k)
{
  if(i>j) return;    //error check condition
  int m = j - i + 1;
  if(m <= k)         //if m <= k use ToH3
   {
     ToH3(i, j, p, q, r);
     return;
   }
  if(i == j)         //if n <= 3 do it directly
   {
     makemove(i, p, q);
     return;
   }
  if(j-i == 1)       //if n < 3 do it directly
    {
      makemove(i, p, r);
      makemove(j, p, q);
      makemove(i, r, q);
      return;
    }
  if(j-i == 2)        //if n < 3 do it directly
    {
      makemove(i, p, s);
      makemove(i+1, p, r);
      makemove(j, p, q);
      makemove(i+1, r, q);
      makemove(i, s, q);
      return;
    }
 
 
  ToH42(i, j - k, p, s, q, r, k);    //move the top 1 to n-k disks into the last peg
  ToH3(j-k+1,j,p,q,r);               //move the bottom k disks into the final peg using 3 pegs
  ToH42(i, j - k, s, q, p, r, k);    //move the top 1 to n-k disks into the final peg
  return;
}

void ToH43(int i,int j,int p,int q,int r,int s)
{
  if(i>j) return;            //error check condition
   if(i == j)                //if n < 3 do it directly
    {
      makemove(i, p, q);
      return;
    }
  if(j-i == 1)               //if n < 3 do it directly
    {
      makemove(i, p, r);
      makemove(j, p, q);
      makemove(i, r, q);
      return;
    }
  if(j-i == 2)                //if n < 3 do it directly
    {
      makemove(i, p, s);
      makemove(i+1, p, r);
      makemove(j, p, q);
      makemove(i+1, r, q);
      makemove(i, s, q);
      return;
    }
  int k = sqrt(2*(j - i + 1));
  ToH43(i, j - k, p, s, q, r);      //move the top 1 to n-k disks into the last peg
  ToH3(j-k+1,j,p,q,r);              //move the bottom k disks into the final peg using 3 pegs
  ToH43(i, j - k, s, q, p, r);      //move the top 1 to n-k disks into the final peg
  return;
}


int main()
{
  int n;
  cout << "Enter the value of n" << endl;
  cin >> n;
  registerme(n);
  startpart(1); ToH41(1,n,0,1,2,3); endpart(1);
  int k = sqrt(n);
  startpart(2); ToH42(1,n,0,1,2,3,k); endpart(2);
  startpart(3); ToH43(1,n,0,1,2,3); endpart(3);
  return 0;
}

  
