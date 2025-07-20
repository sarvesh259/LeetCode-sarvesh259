class Solution {
public:
    int findSmaller(int ind,vector<int>& rating)
    {
        int leftSmaller=0;
        int rightSmaller=0;
        for(int i=0;i<ind;i++)
        {
            if(rating[i]<rating[ind])
            {
                leftSmaller++;
            }
        }
        for(int i=ind+1;i<rating.size();i++)
        {
            if(rating[i]>rating[ind])
            {
                rightSmaller++;
            }
        }
        int ans=(leftSmaller*rightSmaller);
        int leftGreater=ind-leftSmaller;
        int rightGreater=rating.size()-1-ind-rightSmaller;
        // cout<<leftSmaller<<" "<<rightSmaller<<" "<<leftSmaller<<" "<<leftGreater<<" "<<ans<<endl;
        ans+=(rightGreater*leftGreater);
        return ans;
    }
    int numTeams(vector<int>& rating) {
        int ans=0;
        for(int i=1;i<rating.size()-1;i++)
        {
            ans+=findSmaller(i,rating);
        }
        return ans;
    }
};