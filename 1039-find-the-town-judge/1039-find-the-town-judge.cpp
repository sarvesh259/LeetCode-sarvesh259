class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      vector<int> know(n,0),known(n,0);
      for(auto i:trust)
      {
          known[i[1]-1]++;
          know[i[0]-1]++;
      }
      int ans=-1,noz=0;
      for(int i=0;i<n;i++)
      {
        if(known[i]==n-1&&know[i]==0)
        {
          ans=i+1;
          noz++;
        }
      }
      if(noz>1)
          return -1;
        return ans;
        // vector<int> a[n];
        // for(auto i:trust)
        // {
        //   a[i[0]-1].push_back(i[1]-1);
        //   // a[i[1]-1].push_back(i[0]-1);
        // }
        // int noz=0,ans=-1;
        // for(int i=0;i<n;i++)
        // {
        //     if(a[i].size()==0)
        //     {
        //         ans=i+1;
        //         noz++;
        //     }
        // }
        // // cout<<noz<<" ";
        // if(noz>1)
        //   return -1;
        // return ans;
    }
};