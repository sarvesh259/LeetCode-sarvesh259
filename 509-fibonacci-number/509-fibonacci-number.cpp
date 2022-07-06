class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int i1=1,i2=0,ans;
        for(int i=2;i<=n;i++)
        {
            int temp=i1;
            i1=i1+i2;
            i2=temp;            
        }
        return i1;
        
    }
};