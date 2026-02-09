class KthLargest {
public:
    //top would be lowest among k elements in a heap. so push and pop in min heap if greater than top
    int space;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        space = k;
        for(auto num:nums){
            if(space > 0){
                pq.push(num);
                space--;
            }
            else if(space == 0 && nums.size() != 0){
                if(num > pq.top()){
                    pq.pop();
                    pq.push(num);
                }
            }
        }
    }
    
    int add(int val) {
        if(space > 0){
            pq.push(val);
            space--;
        }
        else if(pq.size() == 0){
            return -1;
        }
        else if(val > pq.top()){
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */