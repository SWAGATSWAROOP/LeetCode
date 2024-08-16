class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(),col = mat[0].size();
        vector<vector<int>> v(row,vector<int>(col,-1));

        pair<int,int> front;
        queue<pair<int,int>> q;
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(mat[i][j] == 0){
                    v[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int arrx[] = {-1,0,0,1};
        int arry[] = {0,-1,1,0};
        int count = 1;
        int sz,x,y,xeff,yeff;
        cout<<"Hello"<<endl;
        while(!q.empty()){
            sz = q.size();
            while(sz--){
                front = q.front();
                q.pop();
                x = front.first;
                y = front.second;
                for(int i = 0;i < 4;i++){
                    xeff = x - arrx[i];
                    yeff = y - arry[i];
                    if(xeff >= 0 && xeff < row && yeff >= 0 && yeff < col && v[xeff][yeff] == -1 && mat[xeff][yeff]){
                        v[xeff][yeff] = count;
                        q.push({xeff,yeff});                
                    }
                }
            }
            count++;
        }
        return v;
    }
};