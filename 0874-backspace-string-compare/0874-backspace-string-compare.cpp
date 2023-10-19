class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> st1;
        stack<int> st2;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '#')
            {
                if(st1.empty() == 0)
                {
                    st1.pop();
                }

            }
            else
            {
                st1.push(s[i]);
            }
        }
        for(int i=0;i<t.length();i++)
        {
            if(t[i] == '#')
            {
                if(st2.empty() == 0)
                {
                    st2.pop();
                }

            }
            else
            {
                st2.push(t[i]);
            }
        }
        while(st1.empty() == 0 && st2.empty() == 0)
        {
            if(st1.top() != st2.top())
            {
                return false;
            }
            st1.pop();
            st2.pop();
        }
        if(st1.empty() == 1 && st2.empty() == 1)
            return true;
        return false;
    }
};
