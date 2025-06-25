class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPr=INT_MAX;
        int profit=0;
        for(int i=0;i<prices.size();i++)
        {
            if(minPr>prices[i])
            {
                minPr=prices[i];
            }
            else
            {
                profit=max(profit,prices[i]-minPr);
            }
        }
        return profit;
    }
};