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

// Cycle present
bool is_cycle_present(Node *root)
{
    Node *left = root;
    Node *right = root;

    while(right!=NULL)
    {
        right=(right->next)->next;

        if(right == left)
        {
            return true;
        }

        left=left->next;
    }

    return false;
}

// Middle Element
Node *get_mid_element(Node *root, int x=1, int y=2)
{
    int count=0;
    auto mid = new Node();

    auto head_ref = root;

    while(head_ref->next!=NULL)
    {
        head_ref=head_ref->next;
        count++;
    }

    count++;

    mid = head_ref;

    count=count*x/y;

    while(count>0)
    {
        mid=mid->prev;
        count--;
    }

    return mid;
}

bool binary_search(Node *root, Node *value)
{
    auto mid = get_mid_element(root);
}

int main()
{
    Node *a = new Node();
    Node *b = new Node();
    Node *c = new Node();
    Node *d = new Node();
    Node *e = new Node();
    //Node *f = new Node();
    //Node *x = new Node();

    a->data = 1;
    b->data = 2;
    c->data = 3;
    d->data = 4;
    e->data = 5;
    //f->data = 7;
    //x->data = 11;

    append(a, b);
    append(b, c);
    append(c, d);
    //loop
    //append(d, b);
    append(d, e);
    //append(e, f);

    //cout<<boolalpha<<is_cycle_present(a);

    cout<<get_mid_element(a)->data;

    //print(a);

    //insert(a, x, 2);

    //print(a);

    //pop(a);

    //print(a);

    //sort(&a);

    //print(&a);
    
    return 0; 
}
