class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto a:arr)
        {
            mp[a]++;
        }
        vector<int> freqencies;
        for(auto [_,freq]:mp)
            freqencies.push_back(freq);
        sort(freqencies.begin(), freqencies.end());
        int ans=0,req=arr.size()/2,i=freqencies.size()-1,pp=0;;
        for(auto i:freqencies)
        {
            cout<<i<<" ";
        }
        while(ans<req)
        {
            ans+=freqencies[i];
           // req-=freqencies[i];
            i--;
            pp++;
        }
        return pp;
    }
};