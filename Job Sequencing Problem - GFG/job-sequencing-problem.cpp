//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comp(Job j1,Job j2)
    {
        return j1.profit>j2.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<bool> a(n,true);
        sort(arr,arr+n,comp);
        int prof=arr[0].profit,work=1;
        a[arr[0].dead-1]=0;
        for(int i=1;i<n;++i)
        {
            int j=arr[i].dead-1;
            while(!a[j])
            {
                j--;
                if(j<0)
                    break;
            }
            if(j<0)
                continue;
           else{
                a[j]=false;
                prof+=arr[i].profit;
                work++;
            }
        }
        // for(int i=0;i<n;++i)
        //     cout<<arr[i].profit<<" ";
        // cout<<endl;
        vector<int> ans;
        ans.push_back(work);
        ans.push_back(prof);
        return (ans);
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends