class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int buyMin=INT_MAX;

        for(int i=0;i<prices.size();i++)
        {
            if(buyMin>prices[i])
            {
                buyMin=prices[i];
            }
            else
            {
                ans=max(ans,prices[i]-buyMin);
            }
        }
        return ans;
    }
};