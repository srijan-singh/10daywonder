#include<bits/stdc++.h>

using namespace std;

int max_sum(stack<int> stack1, stack<int> stack2, stack<int> stack3)
{
     int result=0;

     int sum1=0;
     int sum2=0;
     int sum3=0;

     // Sum of stack1
     stack<int> temp_stack = stack1;
     while (not temp_stack.empty())
     {
          sum1+=temp_stack.top();
          temp_stack.pop();
     }

     // Sum of stack2
     temp_stack = stack2;
     while (not temp_stack.empty())
     {
          sum2+=temp_stack.top();
          temp_stack.pop();
     }

     // Sum of stack3
     temp_stack = stack3;
     while (not temp_stack.empty())
     {
          sum3+=temp_stack.top();
          temp_stack.pop();
     }
    
    // finding the max equal sum of three stack
     while (not stack1.empty() and (not stack2.empty() and not stack3.empty()))
     {
          if(sum1 >= sum2 and sum1 >= sum3)
          {
               sum1-=stack1.top();

               if(sum1==sum2 and sum2==sum3)
               {
                    return sum1;
               }
               stack1.pop();
          }

          else if(sum2 >= sum1 and sum2 >= sum3)
          {
               sum2-=stack2.top();

               if(sum1==sum2 and sum2==sum3)
               {
                    return sum2;
               }
               stack2.pop();
          }

          else
          {
               sum3-=stack3.top();
               
               if(sum1==sum2 and sum2==sum3)
               {
                    return sum3;
               }
               stack3.pop();
          }
     }
     
     return result;
}

int main()
{
     vector<int> stack_1 = {3,2,1,1,1};
     vector<int> stack_2 = {4,3,2};
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

     cout<<max_sum(stack1, stack2, stack3);

     return 0;
}