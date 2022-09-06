#include<bits/stdc++.h>

using namespace std;

class Solution
{

     public:
     int trap(vector<int> &arr)
     {
          if(arr.size() == 1)
          {
               return 0;
          }

          int count = 0;

          int left=0;

          while(arr[left]==0) left+=1;

          int right=left+1;
          
          int length=arr.size() -1;
          while(arr[length] < arr[length-1]) length-=1;

          if(length==left)
          {
               return 0;
          }
          

          queue<int> intQueue;
          intQueue.push(left);

          while (left<right)
          {
               if(right = arr.size()) break;

               if(right==length)
               {
                    int sum=0;
                    bool found=false;

                    while(not intQueue.empty())
                    {
                         int top = intQueue.front();

                         if(arr[top] <= arr[right] and not found)
                         {
                              left=top;
                              found=true;
                              
                              intQueue.pop();

                              top = intQueue.front();
                         }

                         if(found)
                         {
                              sum+=arr[top];
                         }

                         intQueue.pop();
                    }

                    int temp_count = abs(left-right) -1;
               
                    int matrix = min(arr[left],arr[right])*temp_count;
                    
                    count+= matrix - sum;

                    return count;
               }

               else
               {
                    if(arr[left] <= arr[right])
                    {
                         int sum=0;

                         intQueue.pop();
                         while(not intQueue.empty())
                         {
                              int top = intQueue.front();

                              sum+=arr[top];
                         
                              intQueue.pop();
                         }

                         int temp_count = abs(left-right) - 1;

                         int matrix = min(arr[left],arr[right])*temp_count;

                         count +=matrix-sum; 

                         left=right;
                    }

                    intQueue.push(right);

                    right++;
               }

          }
          
          return count;
     }

};

int main()
{
     vector<int> arr = {
          0,1,0,2,1,0,1,3,2,1,2,1
          };

     int ans = 9;

     Solution s;
     
     cout<<s.trap(arr);

     return 0;
}