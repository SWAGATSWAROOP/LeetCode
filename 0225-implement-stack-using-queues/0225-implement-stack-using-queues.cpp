class MyStack {
public:
    queue<int> e;
    queue<int> s;
    MyStack() {
        
    }
    
    void push(int x) {
        while(!s.empty()){
            e.push(s.front());
            s.pop();
        }
        s.push(x);
        while(!e.empty()){
            s.push(e.front());
            e.pop();
        }
    }
    
    int pop() {
        if(s.empty())return 0;
        int l = s.front();
        s.pop();
        return l;
    }
    
    int top() {
        if(s.empty())return 0;
        return s.front();
    }
    
    bool empty() {
        if(s.empty())return true;
        return false;
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