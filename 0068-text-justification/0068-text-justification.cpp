class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> vec;
        int charlen = 0;
        int l = 0,r = 0;
        int w = words.size();
        while(l<w && r<w)
        {
            charlen += words[r].length();
            if(charlen < maxWidth)
            {
                r++;
                charlen++;
            }
            else if(charlen == maxWidth)
            {
                string st = "";
                if(l-r-1 == 1)
                {
                    st.append(words[l]);
                    int len = words[l].length();
                    while(len<maxWidth)
                    {
                        st.push_back(' ');
                        len++;
                    }
                    
                }
                else
                {
                    for(int i=l;i<=r;i++)
                    {
                        st.append(words[i]);
                        if(i<r)
                            st.push_back(' ');
                    }
                }
                l = r+1;
                r = l;
                vec.push_back(st);
                charlen =0;
            }
            else
            {
                string st = "";
                if(r-l == 1)
                {
                    st.append(words[l]);
                    int len = words[l].length();
                    while(len<maxWidth)
                    {
                        st.push_back(' ');
                        len++;
                    }
                }
                else
                {
                    int diff = maxWidth - (charlen - (r-l-1) - words[r].length());
                    int diffrem = diff%(r-l-1);
                    diff = diff/(r-l-1);

                    for(int i=l;i<r;i++)
                    {
                        st.append(words[i]);
                        if(i<r-1)
                        {
                            for(int j = 0;j < diff;j++)
                            {
                                st.push_back(' ');
                            }
                            if(diffrem >= i-l)
                            {
                                st.push_back(' ');
                            }
                        }
                    }
                }
                vec.push_back(st);
                charlen =0;
                l=r;
            }
        }
        if(l<w)
        {
            string st = "";
            while(l<w)
            {
                st.append(words[l]);
                st.push_back(' ');
                l++;
            }
            int len= st.length();
            while(len < maxWidth)
            {
                st.push_back(' ');
                len++;
            }
            vec.push_back(st);
        }
        return vec;
    }
};