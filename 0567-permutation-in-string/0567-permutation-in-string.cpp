class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i=0,j=0;
        vector<int> hash(26,0);
        vector<int> hash1(26,0);
        for(int k=0;k<s1.size();k++)
        {
            hash[s1[k]-'a']++;
        }
        while(j<s2.size())
        {
            hash1[s2[j]-'a']++;
            while(hash1[s2[j]-'a']>hash[s2[j]-'a'])
            {
                hash1[s2[i]-'a']--;
                i++;
            }
            if(j-i+1==s1.size()){
                bool flag=true;
                for(int i=0;i<26;i++)
                {
                    if(hash[i]!=hash1[i])
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag) return true;
            }
            j++;
        }
        return false;
    }
};