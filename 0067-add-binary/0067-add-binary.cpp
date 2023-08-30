class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length()-1;
        int len2 = b.length()-1;
        string str = "";
        int carry = 0;
        while(len1!=-1 && len2!=-1)
        {
            int sum  = (a[len1] -'0')+ (b[len2] - '0')+carry;
            carry = sum/ 2;
            sum  = sum%2;
            if(sum == 0)
            {
                str = "0" + str;
            }
            else
            {
                str = "1" + str;
            }
            len1--,len2--;
        }
        if(len1 != -1)
        {
            while(len1 != -1)
            {
                int sum = (a[len1] - '0') + carry;
                carry = sum/2;
                sum = sum%2;
                if(sum == 0)
                {
                    str = "0" + str;
                }
                else
                {
                    str = "1" + str;
                }
                len1--;
            }
        }
        if(len2 != -1)
        {
            while(len2 != -1)
            {
                int sum = (b[len2] - '0') + carry;
                carry = sum/2;
                sum = sum%2;
                if(sum == 0)
                {
                    str = "0" + str;
                }
                else
                {
                    str = "1" + str;
                }
                len2--;
            }
        }
        if(carry == 1)
        {
            str = "1" + str;
        }
        return str;
    }
};