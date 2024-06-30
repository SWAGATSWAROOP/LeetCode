class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0,right = matrix[0].size()-1,up = 0,down = matrix.size()-1;
        int dir = 0;
        int i = 0,j = 0;
        while(i <= down && j <= right && i >= up && j >= left){
            if(dir == 0){
                while(j <= right){
                    ans.push_back(matrix[i][j]);
                    j++;
                }
                dir = 1;
                up++;
                i++;
                j = right;
            }
            else if(dir == 1){
                while(i <= down){
                    ans.push_back(matrix[i][j]);
                    i++;
                }
                dir = 2;
                right--;
                i = down;
                j--;
            }
            else if(dir == 2){
                for(;j >= left;j--)ans.push_back(matrix[i][j]);
                dir = 3;
                down--;
                i--;
                j = left;
            }
            else{
                for(;i >= up;i--)ans.push_back(matrix[i][j]);
                dir = 0;
                left++;
                i = up;
                j++;
            }
        }
        return ans;
    }
};