// LeetCode Logo
// Problem List
// Premium
// 0

// avatar
// Description
// Discussion (93)
// Solutions (13.3K)
// Submissions
// 20. Valid Parentheses
// Easy
// 17.7K
// 977
// Companies
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false
 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.
// Accepted
// 3M
// Submissions
// 7.4M
// Acceptance Rate
// 40.4%

#include<stack>
class Solution {
public:
    bool isValid(string s) {
        int j = s.size();
        if(j%2!=0){
            return false;
        }
        stack<char> st;
        for(int i=0;i<j;i++){
            if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(st.empty() || (st.top()+2 != s[i] && st.top()+1 != s[i])){
                    return false;
                }
                else{
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            } 
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};