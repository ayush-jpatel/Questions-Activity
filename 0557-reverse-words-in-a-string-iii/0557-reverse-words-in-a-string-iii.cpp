class Solution {
public:
    string reverseWords(string s) {
        int low = 0;//i will be the high
        int n = s.length();
        for(int i=0;i<=n;i++)
        {
            if(i == n || s[i] == ' ')
            {
                reverse(s.begin()+low,s.begin()+i);
                low = i+1;
            }
        }
        return s;
    }
};