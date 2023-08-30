//ababb
class Solution {
public:
    bool checkpal(string s, int l ,int r)
    {
        while(l<r)
        {
            if(s[l] != s[r])
            {
                return false;
            }
            l++,r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int l = 0, r = 0;
        int maxlen = 1;
        int maxl = 0,maxr = 0;
        while(r<n)
        {
            if(l == 0 || s[r] != s[l-1])
            {
                while(checkpal(s,l,r) == false)
                {
                    l++;
                }
            }
            else
            {
                l--;
            }
            if((r-l+1)> maxlen)
            {
                maxl = l, maxr = r;
                maxlen = (r-l+1);
            }
            r++;
        }
        return s.substr(maxl,maxr-maxl+1);
    }
};