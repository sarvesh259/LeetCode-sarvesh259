class Solution {
public:
    int calPoints(vector<string>& ops) {
       vector<int> a,b;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="C")
            {
                b.push_back(a[a.size()-1]);
                a.pop_back();
            }
            else if(ops[i]=="D")
            {
                //int temp= a[a.end()-1]*2;
                int temp=a.size()-1;
                a.push_back(a[temp]*2);
            }
            else if(ops[i]=="+")
            {
                int temp=a[a.size()-1]+a[a.size()-2];
                a.push_back(temp);
            }
            else
            {
                a.push_back(stoi(ops[i]));
            }
        }
        int ans=0;
        for(int i=0;i<a.size();i++)
        {
            ans+=a[i];
        }
        return ans;
    }
};