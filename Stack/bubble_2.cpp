#include <iostream>
using namespace std;

#define max_size 50

struct stack {
    int top, size;
    int elements[max_size];
};

int isempty(stack S)
{
    return S.top == -1;
}

int is_full(stack S)
{
    return S.top == S.size - 1;
}

int pop(stack& S)
{
    if(isempty(S))
        return -1000;
    return S.elements[S.top--];
}

void push(stack& S, int x)
{
    if(is_full(S))
    {
        cout<<"Stack is full."<<endl;
        return;
    }
    S.elements[++S.top] = x;    
}

void init_stack(stack &S)
{
    S.size = max_size;
    S.top = -1;
}

void bubble_sort(int a[], int n)
{
    stack s1, s2;
    init_stack(s1);
    for(int i=0; i<n; i++)
        push(s1, a[i]);
    init_stack(s2);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            int aj1 = pop(s1), aj = pop(s1);
            if(aj > aj1  && j != n-1)
                {
                    push(s1, aj1);
                    push(s2, aj);
                    j++;
                } else 
                    push(s1, aj);
        }
    }
}

int main()
{
    int n, a[max_size];
    cout<<"Enter number of elements : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter Number : ";
        cin>>a[i];
    }
    bubble_sort(a, n);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}
