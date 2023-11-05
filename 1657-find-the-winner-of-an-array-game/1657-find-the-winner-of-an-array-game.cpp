class Solution {
public:
    int maxi(vector<int>& arr){
        if(arr.size() == 0)
            return -1;
        int res = arr[0];
        for(int i=0;i<arr.size();i++){
            if(res<arr[i])
                res = arr[i];
        }
        return res;
    }
    int getWinner(vector<int>& arr, int k) {
        int ptr = 1;
        if(k>arr.size()){
            return maxi(arr);
        }
        //store higher position in high, ptr denotes next point to consider
        int high = 0;
        int count = 0;
        while(ptr < arr.size()){
            if(arr[high]>arr[ptr]){
                count++;
                arr.push_back(arr[ptr]);
            }
            else{
                arr.push_back(arr[high]);
                count = 1;
                high = ptr;
            }
            if(count>=k){
                return arr[high];
                break;
            }
            ptr++;
        }
        return 0;
    }
};