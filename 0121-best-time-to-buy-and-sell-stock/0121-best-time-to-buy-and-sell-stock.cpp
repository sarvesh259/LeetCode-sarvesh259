class Solution {
public:
    int maxProfit(vector<int>& prices) {
        deque<int> st;
        int maxProfit=0;
        for(int i=prices.size()-1;i>=0;i--)
        {
            while(!st.empty()&&st.front()<=prices[i])
            {
                st.pop_back();
            }
            if(!st.empty())
            {
                maxProfit = max(st.front()-prices[i],maxProfit);
            }
            st.push_back(prices[i]);
        }
        return maxProfit;
    }
};