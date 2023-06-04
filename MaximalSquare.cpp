// Medium
// 8.9K
// 189
// Companies
// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 4
// Example 2:


// Input: matrix = [["0","1"],["1","0"]]
// Output: 1
// Example 3:

// Input: matrix = [["0"]]
// Output: 0
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix[i][j] is '0' or '1'.
// Accepted
// 585.3K
// Submissions
// 1.3M
// Acceptance Rate
// 45.1%

//Using Dp Space O(mn)
const static auto initialize = [] { std::ios::sync_with_stdio(false); 
std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));
        int mx = 0;
        for(int i=0;i<n;i++){
            v[i][0] = matrix[i][0]-48;
            mx = max(mx,v[i][0]);
        }
        for(int i=1;i<m;i++){
            v[0][i] = matrix[0][i]-48;
            mx = max(mx,v[0][i]);
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1')v[i][j] = 1+min(v[i-1][j-1],min(v[i-1][j],v[i][j-1]));
                mx = max(mx,v[i][j]);
            }
        }
        return mx*mx;
    }
};

//Using Dp space O(n) space;
const static auto initialize = [] { std::ios::sync_with_stdio(false); 
std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(),m = matrix[0].size(),prev;
        vector<int> v(m,0);
        int sz = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp = v[j];
                if(!i || !j || matrix[i][j] == '0')v[j] = matrix[i][j] - '0';
                else v[j] = 1+min(prev,min(v[j],v[j-1]));
                prev = temp;
                sz = max(sz,v[j]);
            }
        }
        return sz*sz;
    }
};