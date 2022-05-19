class Solution {
public:
    int reverse(int x) {
        long long int y=0;
        while(x)
        {
            int t=x%10;
            x=x/10;
            y=(y*10)+t;
        }
        if(y>=2147483647||y<=-2147483647)
            return 0;
        return y;
    }
};