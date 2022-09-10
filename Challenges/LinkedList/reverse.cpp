#include<bits/stdc++.h>

using namespace std;

set<int> memo;

struct Node
{
    int data;
    Node *next = NULL;
};

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

Node* reverse(Node *root, Node *prev=NULL)
{
    if(root == NULL)
    {
        return prev;
    }
    
    auto temp = root->next;

    root->next = prev;
    
    return reverse(temp, root);
}

int main()
{
    Node *a = new Node;
    Node *b = new Node;
    Node *c = new Node;
    Node *d = new Node;
    Node *e = new Node;
    Node *f = new Node;

    a->next = (b);
    b->next = (c);
    c->next = (d);
    d->next = (e);
    e->next = (f);

    a->data = 10;
    b->data = 6;
    c->data = 3;
    d->data = 4;
    e->data = 1;
    f->data = 0;

    print(a);

    a = reverse(a);

    print(a);
    
    return 0; 
}