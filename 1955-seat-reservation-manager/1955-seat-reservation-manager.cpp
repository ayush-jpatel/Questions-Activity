class SeatManager {
public:
    priority_queue<int> heap;
    int ptr;
    SeatManager(int n) {
        ptr = 0;
    }
    //heap signifies unreserved seats before ptr,as all seats after ptr are unreserved
    int reserve() {//heap smallest ne udad, if no heap then inc ptr
        if(heap.size() == 0){
            ptr++;
            return ptr;
        }
        else{
            int x = heap.top() * -1;
            heap.pop();
            return x;
        }
    }
    
    void unreserve(int seatNumber) {//heap ma push kr 
        heap.push(-1*seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */