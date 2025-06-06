class MyQueue {
public:
    stack <int> q1;
    stack <int> q2;
    MyQueue() {
    }
    
    void push(int x) {
        //q2 stores in reverse order
        while(!q2.empty()){
            int t = q2.top(); q2.pop();
            q1.push(t);
        }
        
        q1.push(x);

        while(!q1.empty()){
            int t = q1.top(); q1.pop();
            q2.push(t);
        }
    }
    
    int pop() {
        int t = q2.top();
        q2.pop();
        return t;
    }
    
    int peek() {
        return q2.top();
    }
    
    bool empty() {
        return q2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
