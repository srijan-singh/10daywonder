#include<bits/stdc++.h>

using namespace std;

set<int> memo;

struct Node
{
    int data;
    Node *next = NULL;
    Node *prev = NULL;
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

// Insertion

void append(Node *root, Node *data)
{
    if(root == NULL)
    {
        root = data;
    }

    auto head_ref = root;

    while(head_ref->next!=NULL)
    {
        head_ref = head_ref->next;
    }

    head_ref->next = data;
    data->prev = head_ref;
}

void insert(Node *root, Node* data, int pos)
{
    auto head_ref = root;

    for(int i=0; i<pos; i++)
    {
        if(head_ref==NULL)
        {
            break;
        }

        head_ref = head_ref->next;
    }

    data->prev = head_ref;
    data->next = head_ref->next;
    (head_ref->next)->prev = data;

    head_ref->next = data;
}

// Deletion

void pop(Node *root)
{
    auto head_ref = root;
    
    while(head_ref->next != NULL)
    {
        head_ref = head_ref->next;
    }
    
    auto last_elm = head_ref;

    head_ref = head_ref->prev;

    head_ref->next = NULL;
    last_elm->prev = NULL;

    delete last_elm;
}

int main()
{
    Node *a = new Node();
    Node *b = new Node();
    Node *c = new Node();
    Node *d = new Node();
    Node *e = new Node();
    Node *f = new Node();
    Node *x = new Node();

    a->data = 10;
    b->data = 6;
    c->data = 3;
    d->data = 4;
    //e->data = 1;
    //f->data = 0;
    x->data = 11;

    append(a, b);
    append(b, c);
    append(c, d);
    //append(d, e);
    //append(e, f);

    print(a);

    insert(a, x, 2);

    print(a);

    pop(a);

    print(a);

    //sort(&a);

    //print(&a);
    
    return 0; 
}
