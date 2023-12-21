class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row = img.size(),col = img[0].size();
        vector<vector<int>> v(row,vector<int>(col,0));
        int count;
        bool up = false,down = false;
        for(int i = 0;i < row;i++){
            up = false;down = false;
            if(i - 1 >= 0)up = true;
            if(i+1 < row)down = true;
            for(int j = 0;j < col;j++){
                count = 0;
                v[i][j] += img[i][j];
                count++;
                if(down){v[i][j] += img[i+1][j];
                    count++;
                }
                if(up){v[i][j] += img[i-1][j];
                count++;
                }
                if(j - 1 >= 0){
                    count++;
                    v[i][j] += img[i][j-1];
                    if(down){
                        count++;
                        v[i][j] += img[i+1][j-1];
                    }
                    if(up){
                        count++;
                        v[i][j] += img[i-1][j-1];
                    }
                }
                if(j+1 < col){
                    count++;
                    v[i][j] += img[i][j+1];
                    if(down){
                        count++;
                        v[i][j] += img[i+1][j+1];
                    }
                    if(up){
                        count++;
                        v[i][j] += img[i-1][j+1];
                    }
                }
                v[i][j] /= count;
            }
        }
        return v;
    }
};