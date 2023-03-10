// 371. Sum of Two Integers
// Medium
// 3.4K
// 4.7K
// Companies
// Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

// Example 1:

// Input: a = 1, b = 2
// Output: 3
// Example 2:

// Input: a = 2, b = 3
// Output: 5
 

// Constraints:

// -1000 <= a, b <= 1000
// Accepted
// 371K
// Submissions
// 732.2K
// Acceptance Rate
// 50.7%

class Solution {
public:
    int getSum(int a, int b) {
        return (a | b) + (a & b); 
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0,carry = 0,i = 0;
        while((a || b) && i<32){
            int l  = a & 1,m = b & 1;
            sum |= (carry^l^m)<<i;
            carry = (carry & l) | (l & m) | (carry & m);
            // cout<<carry<<endl;
            i++;
            a >>= 1;
            b >>= 1;
        }
        if(carry && i<32)sum |= 1<<i;
        return sum;
    }
};