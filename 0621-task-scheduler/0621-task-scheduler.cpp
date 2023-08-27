class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)
            return tasks.size();
        // return 0;
        // int maxf=0;
        vector<int> a(26,0);
        for(int i=0;i<tasks.size();i++)
        {
            a[tasks[i]-'A']++;
        }
        sort(a.begin(),a.end(),greater<int>());
        int maxf=(a[0]-1)*n;
        for(int i=1;i<26;i++)
        {
            maxf=maxf-min(a[0]-1,a[i]);
        }
        return tasks.size()+max(0,maxf);
    }
};