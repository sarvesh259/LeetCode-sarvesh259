class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue< pair<int, char> >pq;

        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        for(auto i: mp){
            char c = i.first;
            int freq = i.second;
            pq.push({freq,c});
        }

        string res="";
        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();
            res.append(i.first, i.second);
        }
        return res;
    }
};