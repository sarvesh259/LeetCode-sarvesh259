class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int maxv=verticalCuts[0],maxh=horizontalCuts[0];
        //int v1=0,v2=0,v3=0,v4=0;
        for(int i=1;i<horizontalCuts.size();i++)
        {
            int temp=horizontalCuts[i]-horizontalCuts[i-1];
            maxh=max(maxh,temp);
        }
        for(int i=1;i<verticalCuts.size();i++)
        {
            int temp=verticalCuts[i]-verticalCuts[i-1];
            maxv=max(maxv,temp);
        }
        maxv=max(maxv,w-verticalCuts[verticalCuts.size()-1]);
        maxh=max(maxh,h-horizontalCuts[horizontalCuts.size()-1]);
       //unsigned long long mod=1000000007;
       //unsigned long long  ans=maxv*maxh;
        //ans=ans%mod;
        //cout<<maxv<<" "<<maxh<<endl;
        return (1LL*maxh*maxv) % 1000000007;
    }
};