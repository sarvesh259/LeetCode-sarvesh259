class Solution {
public:
    #include<bits/stdc++.h>
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        if(n<0)
            return digits;
        if(digits[n]!=9)
        {
            digits[n]++;
            return digits;
        }
        int i=n;
        int carry=1;
        while(carry)
        {
            if(digits[i]==9)
            {
                digits[i]=0;
                //carry=1;
            }
            else{
                digits[i]++;
                return digits;
            }
            i--;
            if(i<0)
                break;
        }
       digits.push_back(1);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};