#include<bits/stdc++.h>

using namespace std;

// Prefix
string infixToPrefix(string infix)
{
     string prefix = "";

     stack<char> operation;
     queue<char> variable;

     for(char elm : infix)
     {
          if(isalnum(elm))
          {
               variable.push(elm);
          }

          else
          {
               if(elm=='(' or elm==')') continue;
               
               operation.push(elm);
          }
     }

     while(not operation.empty())
     {
          prefix+=operation.top();
          operation.pop();
     }

     while(not variable.empty())
     {
          prefix+=variable.front();
          variable.pop();
     }

     return prefix;
}

string prefixToInfix(string prefix)
{
     string infix="";

     stack<char> operation;

     for(auto elm:prefix)
     {
          if(isalnum(elm))
          {
               infix+=elm;
               if(not operation.empty())
               {
                    infix+=operation.top();
                    operation.pop();
               }
          }

          else
          {
               operation.push(elm);
          }
     }

     return infix;
}

// Postfix
string infixToPostfix(string infix)
{
     string postfix = "";
     queue<char> operation;

     for(auto elm:infix)
     {
          if(elm=='(' or elm==')') continue;

          if(isalnum(elm))
          {
               // Add elm first
               postfix+=elm;
               // Add operation
               if(not operation.empty())
               {
                    postfix+=operation.front();
                    operation.pop();
               }
          }
          else
          {
               operation.push(elm);
          }
          
     }

     return postfix;
}

string postfixToInfix(string postfix)
{
     string infix="";

     queue<char> variable;
     queue<char> operation;

     for(auto elm : postfix)
     {
          if(isalnum(elm))
          {
               variable.push(elm);
          }
          else
          {
               operation.push(elm);
          }
     }

     while (not variable.empty())
     {
          infix+=variable.front();
          variable.pop();
          if(not operation.empty())
          {
               infix+=operation.front();
               operation.pop();
          }
     }
     

     return infix;
}


int main()
{
     string infix = "(A+B)*C-D";
     cout<<infix<<endl; 
     cout<<infixToPrefix(infix)<<endl;
     cout<<prefixToInfix(infixToPrefix(infix))<<endl;
     cout<<infixToPostfix(infix)<<endl;
     cout<<postfixToInfix(infixToPostfix(infix));

     return 0;
}