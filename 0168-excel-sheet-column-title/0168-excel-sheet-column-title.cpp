class Solution {
public:
    string convertToTitle(int num) {
        string s = "";
        while((num) > 0)
        {
            char ch = (num-1)%26 + 'A';
            s = ch + s;
            num = (num-1)/26;
        }
        return s;
    }
};