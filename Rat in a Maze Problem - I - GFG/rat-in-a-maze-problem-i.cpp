//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void f(int i,int j,int n,string s,vector<vector<int>> &m,vector<string> &ans,vector<vector<bool>> &visi)
    {
        if(i==n-1&&j==n-1)
        {
            ans.push_back(s);
            return;
        }
        if(i+1<n&&m[i+1][j]==1&&visi[i+1][j]==0)
        {
            visi[i+1][j]=1;
            f(i+1,j,n,s+'D',m,ans,visi);
            visi[i+1][j]=0;
        }
        if(j+1<n&&m[i][j+1]==1&&visi[i][j+1]==0)
        {
            visi[i][j+1]=1;
            f(i,j+1,n,s+'R',m,ans,visi);
            visi[i][j+1]=0;
        }
        if(i-1>=0&&m[i-1][j]==1&&visi[i-1][j]==0)
        {
            visi[i-1][j]=1;
            f(i-1,j,n,s+'U',m,ans,visi);
            visi[i-1][j]=0;
        }
        if(j-1>=0&&m[i][j-1]==1&&visi[i][j-1]==0)
        {
            visi[i][j-1]=1;
            f(i,j-1,n,s+'L',m,ans,visi);
            visi[i][j-1]=0;
        }
        return;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0)return {};
        vector<vector<bool>> visi(n,vector<bool>(n,0));
        visi[0][0]=1;
        f(0,0,n,"",m,ans,visi);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends