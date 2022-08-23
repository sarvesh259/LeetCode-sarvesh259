class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1||n==4)
            return 1;
        
        if(n>0&&n%16==0)
        {
            if((n&(n-1))!=0)
                return 0;
            n=n/16;
            int t=sqrt(n);
            return n==t*t;
        }
        return false;
    }
};