class Solution {
public:
    int passThePillow(int n, int time) {
        int roll = 2*n - 2;
        time %= roll;
        int dir = 1;
        int res = 1;
        while(time--){
            if(res == n)
                dir = 0;
            if(dir) res++;
            else res--;
        }
        return res;

    }
};