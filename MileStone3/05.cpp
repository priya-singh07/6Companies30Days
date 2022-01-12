// Stock span problem


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int>v;
       stack<int>st;
       for(int i=0; i<n; i++)
       {
           if(st.empty())
           v.push_back(1);
           else
           {
               while(!st.empty() && price[st.top()] <= price[i])
               st.pop();
               if(st.empty())
               v.push_back(i+1);
               else
               v.push_back(i-st.top());
           }
           st.push(i);
       }
       return v;
    }
};