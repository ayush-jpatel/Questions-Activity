class Solution {
public:
    unordered_map<int,int> mp;
    int recur(string s, int i){
        if(mp[i] != 0)
            return mp[i];
        int n = s.length();
        if(i == n)
            return mp[i] = 1;
        if(i>n || s[i] == '0')
            return mp[i] = 0;
        int sum = 0;
        if(stoi(s.substr(i,2)) <= 26){
            sum = sum+ recur(s,i+2);
            sum = sum+ recur(s,i+1);
        }
        else
            sum += recur(s,i+1);
        return mp[i] = sum;
    }
    int numDecodings(string s) {
        return recur(s,0);
    }
};