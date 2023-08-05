class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int i = 0,n = mat.size(),m = mat[0].size(),j = n-1;
        while(i <= j){
            int mid = i + (j-i)/2;
            int mx = 0;
            for(int k = 1;k<m;k++){
                if(mat[mid][mx] < mat[mid][k]){
                    mx = k;
                }
            }
            int up = mid == 0 ? -1:mat[mid-1][mx];
            int down = mid == n-1 ? -1:mat[mid+1][mx];
            if(mat[mid][mx] > up && mat[mid][mx] > down)return {mid,mx};
            else if(mat[mid][mx] < up)j = mid - 1;
            else i = mid + 1;
        }
        return {-1,-1};
    }
};