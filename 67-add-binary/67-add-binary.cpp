class Solution {
public:
    string addBinary(string a, string b) {
        while(a.size() != b.size())
       {
           if(a.size() > b.size())
               b = "0" + b;
           else
               a = "0" + a;
       }
        string ans = "";
        char rem = '0';
        for(int i=a.size()-1 ; i>=0 ; i--)
        {
            if(a[i] == '0' and b[i] == '0')
            {
                if(rem == '0')
                    ans = "0" + ans;
                else
                {
                    ans = "1" + ans;
                    rem = '0';
                }
            }
            if((a[i]=='0' and b[i]=='1') or (a[i]=='1' and b[i]=='0'))
            {
                if(rem == '0')
                    ans = "1" + ans;
                else
                {
                    ans = "0" + ans;
                    rem = '1';
                }
            }
            if(a[i]=='1' and b[i]=='1')
            {
                if(rem == '0')
                {
                    ans = "0" + ans;
                    rem = '1';
                }
                else
                {
                    ans = "1" + ans;
                    rem = '1';
                }
            }
        }
        if(rem == '1')
            ans = "1" + ans;
        return ans;
    }
};