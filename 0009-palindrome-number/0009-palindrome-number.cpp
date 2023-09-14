class Solution {
public:
    bool isPalindrome(int x) {
        string str = "";
        if(x==0)
            return true;
        if(x<0)
            return false;
        while(x>0)
        {
            int rem = x%10;
            str.push_back(rem+'0');
            x = x/10;
        }
        int n = str.length();
        for(int i=0;i<=n/2;i++)
        {
            if(str[i] != str[n-i-1])
                return false;
        }
        return true;
    }
};