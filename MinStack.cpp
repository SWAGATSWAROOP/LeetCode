// 155. Min Stack
// Medium
// 10.7K
// 710
// Companies
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

 

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
 

// Constraints:

// -231 <= val <= 231 - 1
// Methods pop, top and getMin operations will always be called on non-empty stacks.
// At most 3 * 104 calls will be made to push, pop, top, and getMin.
// Accepted
// 1.2M
// Submissions
// 2.3M
// Acceptance Rate
// 52.1%

class MinStack {
public:
    vector<int> arr;
    int start;
    stack<int> mini;

    MinStack() {
        start = -1;
    }
    
    void push(int val) {
        start++;
        if(start == 0 || mini.top()>=val) mini.push(val);
        arr.push_back(val);
    }
    
    void pop() {
        if(start == -1) return;
        if(arr[start] == mini.top()) mini.pop();
        arr.pop_back();
        start--;
    }
    
    int top() {
        if(start == -1) return 0;
        return arr[start];
    }
    
    int getMin() {
        if(start == -1) return 0;
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */