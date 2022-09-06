#include<bits/stdc++.h>

using namespace std;

int max_top(vector<stack<int>> stacks, int N=2)
{
     int num_of_stack = stacks.size();
     queue<int> q;

     for(int i=0; i<2; i++)
     {
          for(int n=0; n<num_of_stack; n++)
          {
               
          }
     }
     
     return 0;
}

int main()
{
     vector<int> stack_1 = {2,4,6,5};
     vector<int> stack_2 = {1,6,15,10};
     vector<int> stack_3 = {5,4,1};

     reverse(stack_1.begin(), stack_1.end());
     reverse(stack_2.begin(), stack_2.end());
     reverse(stack_3.begin(), stack_3.end());

     stack<int> stack1;
     stack<int> stack2;
     stack<int> stack3;

     for(auto elm : stack_1)
     {
          stack1.push(elm);
     }

     for(auto elm : stack_2)
     {
          stack2.push(elm);
     }

     for(auto elm : stack_3)
     {
          stack3.push(elm);
     }

     //cout<<max_sum(stack1, stack2, stack3);

     vector<stack<int>> stacks = {stack1, stack2};

     cout<<max_top(stacks);

     return 0;
}