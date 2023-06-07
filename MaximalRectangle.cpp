// Hard
// 8.7K
// 139
// Companies
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1
 

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= row, cols <= 200
// matrix[i][j] is '0' or '1'.
// Accepted
// 347.2K
// Submissions
// 770.9K
// Acceptance Rate
// 45.0%

class Solution {
public:
    int StackDP(vector<int> v,int n){
        stack<int> s;
        int area = v[0];
        s.push(0);
        for(int i=1;i<n;i++){
            while(!s.empty() && v[s.top()] >= v[i]){
                int l = s.top();
                s.pop();
                if(s.empty())area = max(area,v[l]*i);
                else area = max(area,v[l]*(i-s.top()-1));
            }
            s.push(i);
        }
        while(!s.empty()){
            int l = s.top();
            s.pop();
            if(s.empty())area = max(area,v[l]*n);
            else area = max(area,v[l]*(n - s.top()-1));
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<int> v(m,0);
        int area = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1')v[j] += 1;
                else v[j] = 0;
            }
            area = max(area,StackDP(v,m));
        }
        return area;
    }
};