class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rl = 0,cl = 0,rh = matrix.size()-1,ch = matrix[0].size()-1,z = ch;
        while(rl <= rh){
            int mid = rl + (rh - rl)/2;
            if(matrix[mid][0] > target)rh = mid - 1;
            else if(matrix[mid][z] < target)rl = mid + 1;
            else{
                while(cl <= ch){
                    int mid2 = cl + (ch - cl)/2;
                    if(matrix[mid][mid2] > target)ch = mid2 - 1;
                    else if(matrix[mid][mid2] < target)cl = mid2  + 1;
                    else return true;
                }
                break;
            }
        }
        return false;
    }
};