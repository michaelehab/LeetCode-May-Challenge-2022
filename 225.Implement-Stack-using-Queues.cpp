class MyStack {
    queue <int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int l = q.size();
        while(l-- > 1){
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
    }
    
    int pop() {
        int tmp = q.front();
        q.pop();
        return tmp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return (q.size() == 0);
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