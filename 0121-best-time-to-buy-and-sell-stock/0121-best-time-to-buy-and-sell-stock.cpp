class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int buyMin=INT_MAX;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(buyMin>prices[i])
            {
                buyMin=prices[i];
            }
            else
                maxProfit=max(maxProfit,prices[i]-buyMin);
        }
        maxProfit=max(maxProfit,prices[prices.size()-1]-buyMin);
        return maxProfit;
    }
};