/*Hard
11.1K
354
Companies
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring
.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
Accepted
625.3K
Submissions
1.9M
Acceptance Rate
32.9%*/


//Space And Time O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(),ma = 0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(s[i] == '(')st.push(i);
            else{
                st.pop();
                if(st.empty())st.push(i);
                ma = max(ma,i-st.top());
            }
        }
        return ma;
    }
};


// Space O(1)
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(),left = 0,right = 0,maxm = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '(')left++;
            else right++;
            if(left == right)maxm = max(maxm,2*left);
            else if(right > left){
                left = 0;
                right = 0;
            }
        }
        left = 0,right = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '(')left++;
            else right++;
            if(left == right)maxm = max(maxm,2*right);
            else if(right < left){
                left = 0;
                right = 0;
            }
        }
        return maxm;
    }
};
