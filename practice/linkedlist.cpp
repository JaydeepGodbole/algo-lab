#include<iostream>

using namespace std;

struct node{
    int u;
    node * next;
};

node * createlist(int a, int n){
    node * head;
    int i;
    node * curr;
    for (i = 0; i < n; i++)
    {
        if(i%a == 0)
        {
            if(i == 0) 
            {
                curr = new(node);
                head = curr;
            }
            else
            {
                curr -> next = new(node);
                curr = curr->next;
            }
            curr->u = i;
            curr -> next = NULL;
        }
    }
    return head;
}

int main()
{
    node * head;
    head = createlist(3, 30);
    while (head != NULL)
    {
        cout << head -> u << end;
        head = head->next;
    }

    return 0;
}