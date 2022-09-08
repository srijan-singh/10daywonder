#include<bits/stdc++.h>

using namespace std;

set<int> memo;

struct Node
{
    int data;
    Node *next = NULL;
    Node *prev = NULL;
    bool visited = false;
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

void common_element(Node *root_a, Node *root_b)
{
    int length_a = 0;
    int length_b = 0;

    auto head_ref_a = root_a;
    auto head_ref_b = root_b;

    while (head_ref_a!=NULL)
    {
        length_a+=1;
        head_ref_a=head_ref_a->next;
    }

    while (head_ref_b!=NULL)
    {
        length_b+=1;
        head_ref_b=head_ref_b->next;
    }

    head_ref_a = root_a;
    head_ref_b = root_b;

    if(length_a < length_b)
    {
        int diff=length_b-length_a;
        while(diff!=0)
        {
            head_ref_b=head_ref_b->next;
            diff--;
        }
    }
    else
    {
        int diff=length_a-length_b;
        while(diff!=0)
        {
            head_ref_a=head_ref_a->next;
            diff--;
        }
    }

    while(head_ref_a!=NULL and head_ref_b !=NULL)
    {
        if(head_ref_a==head_ref_b)
        {
            cout<<head_ref_a->data;
            return;
        }
        head_ref_a=head_ref_a->next;
        head_ref_b=head_ref_b->next;
    }

    return;

}

int main()
{
    Node *a = new Node();
    Node *b = new Node();
    Node *c = new Node();
    Node *d = new Node();
    Node *e = new Node();
    
    Node *x = new Node();
    Node *y = new Node();
    Node *z = new Node();
    

    a->data = 1;
    b->data = 2;
    c->data = 3;
    d->data = 4;
    e->data = 5;
    //f->data = 7;
    x->data = 11;
    y->data = 2;
    z->data = 13;

    append(a, b);
    append(b, c);
    append(c, d);
    append(d, e);
    //append(e, f);

    append(x, y);
    append(y, z);
    append(z, c);


    common_element(a, x);

    //print(a);

    //insert(a, x, 2);

    //print(a);

    //pop(a);

    //print(a);

    //sort(&a);

    //print(&a);
    
    return 0; 
}
