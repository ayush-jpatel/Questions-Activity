class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long int sum1=0,sum2=0;
        long long int blanks1 = 0, blanks2 = 0;
        for(int i=0;i<nums1.size();i++){
            sum1 += nums1[i];
            if(!nums1[i]){
                blanks1++;
            }
        }
        for(int i=0;i<nums2.size();i++){
            sum2 += nums2[i];
            if(!nums2[i]){
                blanks2++;
            }
        }
        if((sum1+blanks1)==(sum2+blanks2)){
            return (sum1+blanks1);
        }
        if((sum1+blanks1)>(sum2+blanks2)){
            if(blanks2 == 0){
                return -1;
            }
            else{
                return (sum1+blanks1);
            }
        }
        if((sum1+blanks1)<(sum2+blanks2)){
            if(blanks1 == 0){
                return -1;
            }
            else{
                return (sum2+blanks2);
            }
        }
        return -1;


    }
};