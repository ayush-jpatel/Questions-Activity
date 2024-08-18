class Solution {
public:
    
    bool reduce(int i,vector<int> &ugly){
        if(i == 1)
            return true;
        for(auto smallugly:ugly){
            while(i%smallugly == 0){
                i/=smallugly;
            }
        }
        // while(i%2 == 0)
        //     i/=2;
        // while(i%3 == 0)
        //     i/=3;
        // while(i%5 == 0)
        //     i/=5;
        return i==1;
    }

    bool wowMethod(int num,vector<int>& wow){
        if(num == 1)    return true;
        
        // if(num == min(wow[num]*2))
        // for(int i=0;i<3;i++){
            // if(num == wow[i])
        // }
        return false;
    }

    int solution(int n){
        if(n <= 0) return false; // get rid of corner cases 
        if(n == 1) return true; // base case
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        vector<int> k(n);
        k[0] = 1;
        for(int i  = 1; i < n ; i ++)
        {
            k[i] = min(k[t2]*2,min(k[t3]*3,k[t5]*5));
            if(k[i] == k[t2]*2) t2++; 
            if(k[i] == k[t3]*3) t3++;
            if(k[i] == k[t5]*5) t5++;
        }
        return k[n-1];
    }
    int nthUglyNumber(int n) { 

        return solution(n);
        // vector<int> ugly;
        vector<int> wow = {2,3,5};
        int i;
        for(i=1;;i++){
            // if(reduce(i,ugly)){
            //     ugly.push_back(i);
            //     n--;
            // }
            if(wowMethod(i,wow)){
                n--;
            }
            if(n == 0)
                break;
        }
        return i;
    }
};