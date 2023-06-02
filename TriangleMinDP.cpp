// 120. Triangle
// Medium
// 8.2K
// 484
// Companies
// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// Example 2:

// Input: triangle = [[-10]]
// Output: -10
 

// Constraints:

// 1 <= triangle.length <= 200
// triangle[0].length == 1
// triangle[i].length == triangle[i - 1].length + 1
// -104 <= triangle[i][j] <= 104
 

// Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
// Accepted
// 596.2K
// Submissions
// 1.1M
// Acceptance Rate
// 54.7%

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i=1;i<n;i++){
            triangle[i][0] += triangle[i-1][0];
            triangle[i][i] += triangle[i-1][i-1];
        }
        for(int i=2;i<n;i++){
            for(int j=1;j<i;j++){
                triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j]);
            }
        }
        int mn = INT_MAX;
        for(int i=0;i<n;i++)mn = min(mn,triangle[n-1][i]);
        return mn;
    }
};