// 59. Spiral Matrix II
// Medium
// 4.6K
// 203
// Companies
// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

// Example 1:


// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
// Example 2:

// Input: n = 1
// Output: [[1]]
 

// Constraints:

// 1 <= n <= 20
// Accepted
// 419.5K
// Submissions
// 625.4K
// Acceptance Rate
// 67.1%

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n,0));
        int rs = 0,cs = 0,re = n-1,ce = n-1,count = 1,m=n*n;
        while(count<=m){
            int i = rs,j = cs;
            for(;j<=ce && count<=m;j++){
                v[i][j] = count;
                count++;
            }
            i++;
            j--;
            for(;i<=re && count<=m;i++){
                v[i][j] = count;
                count++;
            }
            i--;
            j--;
            for(;j>=cs && count<=m;j--){
                v[i][j] = count;
                count++;
            }
            j++;
            i--;
            for(;i>rs && count<=m;i--){
                v[i][j] = count;
                count++;
            }
            rs++;
            cs++;
            ce--;
            re--;
        }
        return v;
    }
};