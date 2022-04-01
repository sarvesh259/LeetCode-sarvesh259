class Solution {
public:
    void reverseString(vector<char>& s) {
        int a=0;
        int i=s.size()-1;
        while(a<i)
        {
            char temp=s[i];
            s[i]=s[a];
            s[a]=temp;
            i--;
            a++;
        }
    }
};