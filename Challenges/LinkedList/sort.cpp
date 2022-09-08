#include<bits/stdc++.h>

using namespace std;

set<int> memo;

struct Node
{
    int data;
    Node *next = NULL;
};

void sort(Node *root)
{
    auto head_ref = root;

    while(head_ref!=NULL)
    {
        memo.insert(head_ref->data);
        head_ref=head_ref->next;
    }

    head_ref=root;

    for(auto elm : memo)
    {
        head_ref->data = elm;
        head_ref = head_ref->next;
    }
}

void print(Node *root)
{
    auto head_ref = root;

    while(head_ref!=NULL)
    {
        cout<<head_ref->data<<" ";
        head_ref = head_ref->next;
    }
    cout<<endl;
}

int main()
{
    Node a;
    Node b;
    Node c;
    Node d;
    Node e;
    Node f;

    a.next = (&b);
    b.next = (&c);
    c.next = (&d);
    d.next = (&e);
    e.next = (&f);

    a.data = 10;
    b.data = 6;
    c.data = 3;
    d.data = 4;
    e.data = 1;
    f.data = 0;

    print(&a);

    sort(&a);

    print(&a);
    
    return 0; 
}