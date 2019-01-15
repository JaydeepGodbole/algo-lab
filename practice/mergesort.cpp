#include<iostream>

using namespace std;

void mergesort(int *p, int n)
{
    //Sorts an array pointed by p and till the index n-1 i.e. from p to p + n-1
    if(n<=1) return;
   /* else if (n == 2)
    {
        int temp = *p;
        *p = *(p+1);
        *(p + 1) = *p;
        return;
    }*/
    mergesort(p, n/2);
    mergesort(p + n/2, n - n/2);
    int *q = new int[n];
    int count1 = 0;
    int count2 = 0;
    int i = 0;
    while(count1 < n/2 && count2 < n - n/2)
    {
        if(p[count1] < p[n/2 + count2])
        {
            q[i] = p[count1];
            count1++;
            i++;
        }
        else
        {
            q[i] = p[n/2 + count2];
            count2++;
            i++;
        }
    }
    if(count1 == n/2)
        {
            while(count2 != n-n/2)
            {
                q[i] = p[n/2 + count2];
                i++;
                count2++;
            }
        }
    else if(count2 == n-n/2)
    {
        while(count1 != n/2)
        {
            q[i] = p[count1];
            i++;
            count1++;
        }
    }

    for(i = 0; i<n; i++)
    {
        p[i] = q[i];
    }
    delete(q);
    return;
}

int main()
{
    int n;
    cin >> n;
    int *p = new int[n];
    int i;
    for(i = 0; i<n; i++)
    {
        cin >> p[i];
    }
    mergesort(p, n);
    cout << "print the array" << endl;
    for(i = 0;i <n; i++)
    {
        cout << p[i] << endl;
    }
}