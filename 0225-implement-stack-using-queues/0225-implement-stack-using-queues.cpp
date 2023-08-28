class MyStack {
public:
queue<int> q1;
queue<int> q2;
int ptr = 1;
    MyStack() {
        
    }
    
    void push(int x) {
        if(ptr == 1)//1 means 1 has all elements, 2 is empty
        {
            q1.push(x);
        }
        else
        {
            q2.push(x);
        }
    }
    
    int pop() {
        if(ptr == 1)
        {
            int n = q1.size();
            for(int i=0;i<n-1;i++)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int temp = q1.front();
            q1.pop();
            ptr = 2;
            return temp;
        }
        else
        {
            int n = q2.size();
            for(int i=0;i<n-1;i++)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int temp = q2.front();
            q2.pop();
            ptr = 1;
            return temp;
        }
    }
    
    int top() {
        if(ptr == 1)
        {
            int n = q1.size();
            for(int i=0;i<n-1;i++)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int temp = q1.front();
            q1.pop();
            q2.push(temp);
            ptr = 2;
            return temp;
        }
        else
        {
            int n = q2.size();
            for(int i=0;i<n-1;i++)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int temp = q2.front();
            q2.pop();
            q1.push(temp);
            ptr = 1;
            return temp;
        }
    }
    
    bool empty() {
        if(ptr == 1)
            return q1.empty();
        else
            return q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */