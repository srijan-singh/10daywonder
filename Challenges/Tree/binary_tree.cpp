#include<bits/stdc++.h>

using namespace std;

class BST
{
     struct Node
     {
          int data;
          Node *left = NULL;
          Node *right = NULL;
     };

     Node *root = NULL;

     Node *insertion(Node *root, int data)
     {
          if(root==NULL)
          {
               root = new Node();
               root->data = data;
          }

          else if(root->data > data)
          {
               root->left = insertion(root->left, data);
          }

          else
          {
               root->right = insertion(root->right, data);
          }

          return root;
     }

     void inorder_display(Node *root)
     {
          if(root==NULL) return;
          inorder_display(root->left);
          cout<<root->data<<' ';
          inorder_display(root->right);
     }

     void preorder_display(Node *root)
     {
          if(root==NULL) return;
          cout<<root->data<<' ';
          preorder_display(root->left);
          preorder_display(root->right);
     }

     void postorder_display(Node *root)
     {
          if(root==NULL) return;          
          postorder_display(root->left);
          postorder_display(root->right);
          cout<<root->data<<' ';
     }

     public:

     void insert(int data)
     {
          root = insertion(root, data);
     }

     void inorder()
     {
          inorder_display(root);
          cout<<endl;
     }

     void preorder()
     {
          preorder_display(root);
          cout<<endl;
     }

     void postorder()
     {
          postorder_display(root);
          cout<<endl;
     }

};

int main()
{
     BST b;
     b.insert(4);
     b.insert(1);
     b.insert(3);
     b.insert(2);

     b.inorder();
     b.preorder();
     b.postorder();

     return 0;
}