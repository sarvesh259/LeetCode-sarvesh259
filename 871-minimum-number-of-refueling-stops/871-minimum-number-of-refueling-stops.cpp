class Solution {
public:
    int minRefuelStops(int target, int fuel, vector<vector<int>>& s) {
        priority_queue<int> pq;
        int t=0,i;
        for(i=0;fuel<target;i++)
        {
            while(t<s.size()&&fuel>=s[t][0])
            {
                pq.push(s[t][1]);
                t++;
            }
            if(pq.empty())
                return -1;
            fuel+=pq.top();
            pq.pop();
        }
        return i;
    }
};