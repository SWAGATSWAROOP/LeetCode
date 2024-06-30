class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        for(int i = 0;i < row;i++){
            for(int j = 0;j <= i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        int i = 0,j = row-1;
        while(i < j){
            for(int k = 0;k < row;k++){
                swap(matrix[k][i],matrix[k][j]);
            }
            i++;
            j--;
        }
    }
};