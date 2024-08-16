class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size(),col = image[0].size();
        vector<vector<int>> v(row,vector<int>(col,0));

        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                v[i][j] = image[i][j];
            }
        }
    
        queue<pair<int,int>> q;
        int xcoor[] = {-1,0,0,1};
        int ycoor[] = {0,-1,1,0};
        int effxcorr,effycoor;
        int x,y;
        q.push({sr,sc});
        int sz = q.size();
        pair<int,int> front;
        while(!q.empty()){
            sz = q.size();
            while(sz--){
                front = q.front();
                x = front.first;
                y = front.second;
                for(int i = 0;i < 4;i++){
                    effxcorr = x - xcoor[i];
                    effycoor = y - ycoor[i];
                    if((effxcorr >= 0) && (effxcorr < row) && (effycoor >= 0) && (effycoor < col) && (v[effxcorr][effycoor] != color) && (v[effxcorr][effycoor] == v[x][y])){
                        q.push({effxcorr,effycoor});
                    }
                }
                q.pop();
                v[x][y] = color;
            }
        }
        return v;
    }
};