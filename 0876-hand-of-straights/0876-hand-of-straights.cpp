class Solution {
public:
    bool f(vector<int> &temp)
    {
        for(int i=1;i<temp.size();i++)
        {
            if(temp[i]-temp[i-1]!=1)
                return false;
        }
        return true;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> mp;
        for(int i=0;i<hand.size();i++)
        {
            mp[hand[i]]++;
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto i:mp)
        {
            pq.push(i.first);
        }
        while(!pq.empty())
        {
            vector<int> temp;
           
             for (int i = 0; i < groupSize; i++) {
                if (!pq.empty()) {
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }

            for (int i = 0; i < temp.size(); i++) {
                if (--mp[temp[i]] > 0) {
                    pq.push(temp[i]);
                }
            }
            if(temp.size()==groupSize)
            {
                if(!f(temp))
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};