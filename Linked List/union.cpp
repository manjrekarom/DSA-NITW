#include <iostream>
using namespace std;

struct lnode 
{
    int data;
    lnode *next;
};
typedef lnode *lptr;
lptr add(lptr l, int k)
{

    if(l == NULL)
    {
        l = new lnode;
        l->data = k;
        l->next = NULL;
    } else {
        lptr t = l;
        while(t->next != NULL)
            t = t->next;
        t->next = new lnode;
        t->next->next = NULL;
        t->next->data = k;
        t = t->next;
    }
    return l;
}

int search(lptr l, int k)
{
    while(l != NULL)
    {
        if(l->data == k)
            return 1;
        l = l->next;
    }
    return 0;
}

lptr unio(lptr l1, lptr l2, lptr l3)
{
    lptr t = l1;
    while(t != NULL)
    {
        l3 = add(l3, t->data);
        t = t->next;
    }
    while(l2 != NULL)
    {
        if(search(l1, l2->data) == 0)
            l3 = add(l3, l2->data);
        l2 = l2->next;
    }
    return l3;
}

void print(lptr l)
{
    while(l != NULL)
    {
        cout<<l->data<<" -> ";
        l = l->next;
    }
    cout<<"NULL\n";
}

int main()
{
    lptr l1 = NULL, l2 = NULL, l3 = NULL;
    int n, m;
    cout<<"Enter No. of Elements for L1 : ";
    cin>>n;
    for(; n>0; n--)
    {
        int k;
        cout<<"Enter Value : ";
        cin>>k;
        l1 = add(l1, k);
    }
    cout<<"Enter No. of Elements for L2 : ";
    cin>>m;
    for(; m>0; m--)
    {
        int k;
        cout<<"Enter Value : ";
        cin>>k;
        l2 = add(l2, k);
    }
    l3 = unio(l1, l2, l3);
    print(l3);
    return 0;
}