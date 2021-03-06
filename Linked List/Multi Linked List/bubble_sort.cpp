#include <iostream>
#include <stdio.h>
using namespace std;

#define max_size 50

struct mlnode 
{
    int tag;
    union u {
        char element;
        mlnode *down;
    } data;
    mlnode *next;
};

typedef mlnode *mlptr;

void print(mlptr node)
{   
    if(node == NULL)
        return ;
    if(node->tag == 0)
    {
        if(node->data.element)
            cout<<node->data.element<<", ";
        print(node->next);
    }
    else if(node->tag == 1){
        cout<<"(";
        print(node->data.down);
        cout<<")";
        if(node->next != NULL)
            print(node->next);
    }
}

mlptr init(mlptr m)
{
    m = new mlnode;
    m->next = NULL;
    return m;
}

mlptr create(mlptr head, char a[])
{
    mlptr run = head, old[max_size];
    int old_count = 0;
    for(int i=0; a[i]; i++)
        if(a[i] == '(')
        {
            run->tag = 1;
            run->data.down = new mlnode;
            old[old_count++] = run;
            run = run->data.down;
        } else if (a[i] == ')')
        {
            run->next = NULL;
            run = old[--old_count];
            run->next = new mlnode;
            run = run->next;
        }
        else if(a[i] == ',' || a[i] == ' ');
        else {
            run->tag = 0;            
            run->data.element = a[i];
            run->next = new mlnode;
            run = run->next;
        }
    run->next = NULL;
    return head;
}

void swap(char &a, char &b)
{
    char l = a;
    a = b;
    b = l;
}

mlptr bubble_sort(mlptr head)
{
    mlptr outer = head;
    while(outer->next != NULL)
    {
        mlptr k = head;
        while(k->next != NULL)
        {
            if(k->tag == 0)
            {
                if(k->next->tag == 0)
                {
                    if(k->data.element > k->next->data.element)
                        swap(k->data.element, k->next->data.element);
                }
                else {
                    mlptr g = k->next->next;
                    while(g->tag != 0)
                        g = g->next;
                    if(k->data.element > g->data.element)
                        swap(k->data.element, g->data.element);
                }   
            } else 
                k->data.down = bubble_sort(k->data.down);
            k = k->next;
        }
        outer = outer->next;
    }
    return head;
}

int main()
{
    mlptr head;
    head = init(head);
    char a[max_size];
    cout<<"Enter Expression : ";
    gets(a);
    head = create(head, a);
    head = bubble_sort(head);
    print(head);
    return 0;
}