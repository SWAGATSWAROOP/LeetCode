class MyStack {
public:
    queue<int> e;
    queue<int> s;
    MyStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        while(!e.empty()){
            s.push(e.front());
            e.pop();
        }
        swap(s,e);
    }
    
    int pop() {
        if(e.empty())return 0;
        int l = e.front();
        e.pop();
        return l;
    }
    
    int top() {
        if(e.empty())return 0;
        return e.front();
    }
    
    bool empty() {
        if(e.empty())return true;
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