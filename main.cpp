#include<bits/stdc++.h>

using namespace std;

class FreqStack 
{
    stack<int> intStack;
    map<int, int> memo;
    
    int freq = 0;
    
    void max_freq()
    {        
        freq=0;
        for(auto elm : memo)
        {
            if(freq <= elm.second)
            {
                freq=elm.second;
            } 
        }
    }
    
public:
    void push(int elm) 
    {
        if(memo.find(elm) != memo.end())
        {
            memo[elm] += 1;
        }
        else
        {
            memo[elm] = 1;
        }
        
        intStack.push(elm);   
    }
    
    int pop() 
    {
        max_freq();
        
        stack<int> buffer;
        
        int last_elm = memo[intStack.top()];
        
        while(last_elm != freq and not intStack.empty())
        {
          buffer.push(intStack.top());
          intStack.pop();

          last_elm = memo[intStack.top()];

        }
        
        int last = intStack.top();
        intStack.pop();
        
        memo[last] -= 1;
        
        while(not buffer.empty())
        {
            intStack.push(buffer.top());
            buffer.pop();
        }
        
        return last;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

int main()
{
     FreqStack freqStack;
     freqStack.push(5); // The stack is [5]
     freqStack.push(7); // The stack is [5,7]
     freqStack.push(5); // The stack is [5,7,5]
     freqStack.push(7); // The stack is [5,7,5,7]
     freqStack.push(4); // The stack is [5,7,5,7,4]
     freqStack.push(5); // The stack is [5,7,5,7,4,5]
     cout<<freqStack.pop()<<endl;   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
     cout<<freqStack.pop()<<endl;   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
     cout<<freqStack.pop()<<endl;   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
     cout<<freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
     return 0;
}