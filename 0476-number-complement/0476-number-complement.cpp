class Solution {
public:
    int try2(int num){
        int sum = 0; 
        int dig = 1;
        while((num & dig) == 0){
            sum += dig;
            dig <<= 1;
        }
        return sum;
    }
    int findComplement(int num) {
        // return try2(num);
        
        long long int comp = 1;
        if(num == 1)
            return 0;
        // if(num == 2147483647 || num == 2147483646)
            // return 0;
        while(comp<=num){
            // if(comp-1 == num)
            //     return 0;
            comp<<= 1;
        }
        comp--;
        // cout << comp << endl;
        return num^comp;
    }
};