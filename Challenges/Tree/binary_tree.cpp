#include<bits/stdc++.h>

using namespace std;

template<typename dataType>class BST
{
     struct Node
     {
          dataType data;
          Node *left = NULL;
          Node *right = NULL;
     };

     Node *root = NULL;

     Node *insertion(Node *root, dataType data)
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

     Node *deletion(Node *root, dataType data)
     {
          if(root->data == data)
          {
               if(root->left)
               {
                    cout<<"issue\n";
                    auto max = max_elm(root->left);
                    auto root_ref = root->left;

                    while(root_ref->right != max)
                    {
                         root_ref = root_ref->right;
                    }

                    root_ref->right = NULL;

                    max->left = root->left;
                    max->right = root->right;

                    root = max;

                    delete max;         
               }

               else if(root->right)
               {
                    auto min = min_elm(root->right);
                    auto root_ref = root->right;

                    while(root_ref != min)
                    {
                         root_ref = root_ref->left;
                    }

                    root->data = min->data;

                    while(root->right != NULL)
                    {
                         root = root->right;
                    }

                    delete root;
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

     void levelorder_display(Node *root)
     {
          queue<Node*> buffer;

          buffer.push(root);

          while(not buffer.empty())
          {
               auto front = buffer.front();
               buffer.pop();

               cout<<front->data<<' ';

               if(front->left) buffer.push(front->left);
               if(front->right) buffer.push(front->right);
          }
     }

     void left(Node *root, stack<dataType> buffer = {})
     {
          if(root==NULL)
          {
               while(not buffer.empty())
               {
                    cout<<buffer.top()<<' ';
                    buffer.pop();
               }
               return;
          } 
          buffer.push(root->data);
          left(root->left, buffer);
     }

     void right(Node *root)
     {
          if(root==NULL) return;
          cout<<root->data<<" ";
          right(root->right);
     }

     void side_tree(Node *root)
     {
          queue<Node*> leftBuffer;
          queue<Node*> rightBuffer;

          auto left = root->left;
          auto right = root->right;
          
          while (left!=NULL)
          {
               leftBuffer.push(left);
               left = left->left;
          }

          while(right!=NULL)
          {
               rightBuffer.push(right);
               right = right->right;
          }

          while(not leftBuffer.empty() and not rightBuffer.empty())
          {
               cout<<leftBuffer.front()->data<<' ';
               leftBuffer.pop();

               cout<<rightBuffer.front()->data<<' ';
               rightBuffer.pop();
          }

          while(not leftBuffer.empty())
          {
               cout<<leftBuffer.front()<<' ';
               leftBuffer.pop();
          }

          while(not rightBuffer.empty())
          {
               cout<<rightBuffer.front()<<' ';
               rightBuffer.pop();
          }
     }

     public:

     void insert(dataType data)
     {
          root = insertion(root, data);
     }

     void delete_elm(dataType data)
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

     void levelorder()
     {
          levelorder_display(root);
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

     void side()
     {
          left(root->left);
          cout<<root->data<<' ';
          right(root->right);
          cout<<endl;
     }

     void sideQueue()
     {
          cout<<root->data<<' ';
          side_tree(root);
          cout<<endl;
     }
};

int main()
{
     BST<int> b;

     vector<int> elms = {12, 6, 8, 19, 21, 11, 3, 5, 4, 24, 18};

     elms = {10, 6, 15, 4, 7, 12, 19, 3, 5, 11, 20};

     for(auto elm : elms)
     {
          b.insert(elm);
     }

     b.inorder();
     b.preorder();

     /*
     b.delete_elm(12);

     b.inorder();
     b.preorder();
     */


     b.side();
     b.sideQueue();
     
     //b.levelorder();

     return 0;
}
