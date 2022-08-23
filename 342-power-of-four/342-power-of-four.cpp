class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1||(n&(n-1))>0)
            return 0;
        int t=1;
        while(t<=n)
        {
            if(t==n)
                return 1;
            t=t<<1;
            t=t<<1;
        }
        return 0;
    }
};