//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void f(vector<int> &ans,vector<int> &arr,int i,int n,int sum)
    {
        if(i==n)
        {
            ans.push_back(sum);
            return;
        }
        f(ans,arr,i+1,n,sum+arr[i]);
        f(ans,arr,i+1,n,sum);
        return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
       vector<int> ans;
       f(ans,arr,0,N,0);
    
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends