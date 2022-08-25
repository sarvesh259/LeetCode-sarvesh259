class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1)
            return 0;
        int t=log10(n)/log10(3);
        if(pow(3,t)==n)
            return true;
        return false;
    }
};