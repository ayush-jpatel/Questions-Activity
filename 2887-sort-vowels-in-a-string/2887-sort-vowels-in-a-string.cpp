class Solution {
public:
    bool isvowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
        {
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        vector<char> vowels;
        for(int i=0;i<s.length();i++)
        {
            if(isvowel(s[i]))
            {
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(),vowels.end());
        string res;
        int pos = 0;
        for(int i=0;i<s.length();i++)
        {
            if(isvowel(s[i]))
            {
                res.push_back(vowels[pos]);
                pos++;
            }
            else
            {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};