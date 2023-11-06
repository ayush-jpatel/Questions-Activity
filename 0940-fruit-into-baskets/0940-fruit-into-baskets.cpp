class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0,r = 1;
        int n = fruits.size();
        if(n<=2)
            return n;
        int a = fruits[0], b = fruits[1];
        for(int i=1;i<n;i++){
            if(fruits[i]!= a){
                b = fruits[i];
                r = i;
                break;
            }
        }
        int maxi = r-l+1;
        while(r<n-1){
            if(fruits[r+1]!= a && fruits[r+1]!= b){
                a = fruits[r];
                l=r;
                while(l>=0 && fruits[l]== a){
                    l--;
                }
                if(fruits[l] != a){
                    l++;
                }
                b = fruits[r+1];
                r++;
            }
            else{
                r++;
            }
            maxi = max(r-l+1,maxi);
        }
        return maxi;
    }
};