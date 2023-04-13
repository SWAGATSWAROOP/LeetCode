// 946. Validate Stack Sequences
// Medium
// 5.2K
// 97
// Companies
// Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

 

// Example 1:

// Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
// Output: true
// Explanation: We might do the following sequence:
// push(1), push(2), push(3), push(4),
// pop() -> 4,
// push(5),
// pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
// Example 2:

// Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
// Output: false
// Explanation: 1 cannot be popped before 2.
 

// Constraints:

// 1 <= pushed.length <= 1000
// 0 <= pushed[i] <= 1000
// All the elements of pushed are unique.
// popped.length == pushed.length
// popped is a permutation of pushed.
// Accepted
// 248.8K
// Submissions
// 360.4K
// Acceptance Rate
// 69.0%


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(),m = popped.size(),i = 0,j = 0;
        stack<int> s;
        while(i<n && j<m){
            while(i<n && popped[j] != pushed[i])s.push(pushed[i++]);
            j++;
            i++;
            while(j<m && !s.empty() && s.top()==popped[j]){
                s.pop();
                j++;
            }
        }
        cout<<i<<" "<<j<<endl;
        if(i<n || j<m)return false;
        return true;
    }
};