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

     Node *deletion(Node *root, int data)
     {
          if(root->data == data)
          {
               cout<<root->data<<endl;
               auto min = min_elm(root);
               auto root_ref = root;

               if(root->left != NULL)
               {
                    while(root_ref->left != min)
                    {
                         root_ref = root_ref->left;
                    }

                    cout<<root->data<<endl;
                    root_ref->left = NULL;
                    root->data = min->data;
               }

               else if(root->right != NULL)
               {
                    cout<<"works!\n";

                    auto next = root->right;
                    root->left = next->left;
                    root->right = next->right;

                    root->data = next->data;
                    
               }

               else
               {
                    root = NULL;
               }
               
               
          }

          else if(root->data > data)
          {
               root->left = deletion(root->left, data);
          }

          else
          {
               root->right = deletion(root->right, data);
          }

          return root;
     }

     Node *min_elm(Node *root)
     {
          if((root->left == NULL and root->right == NULL) or (root->left == NULL and root->right != NULL))
          {
               return root;
          }

          return min_elm(root->left);
     }

     Node* max_elm(Node *root)
     {
          if((root->left == NULL and root->right == NULL) or (root->left != NULL and root->right == NULL))
          {
               return root;
          }

          return max_elm(root->right);
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

     void delete_elm(int data)
     {
          root = deletion(root, data);
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

     int min()
     {
          return min_elm(root)->data;
     }

     int max()
     {
          return max_elm(root)->data;
     }
};

int main()
{
     BST b;

     vector<int> elms = {12, 6, 8, 19, 21, 11, 3, 5, 4, 24, 18};

     for(auto elm : elms)
     {
          b.insert(elm);
     }


     b.inorder();
     b.preorder();
     //b.postorder();

     //cout<<b.min()<<endl;     
     //cout<<b.max()<<endl;

     b.delete_elm(21);

     b.inorder();

     return 0;
}