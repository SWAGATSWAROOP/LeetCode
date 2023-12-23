class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,bool> map;
        map[{0,0}] = true;
        int n = path.size(),inx = 0,iny = 0;
        for(auto i:path){
            if(i == 'N')iny++;  
            else if(i == 'S')iny--;
            else if(i == 'E')inx++;
            else inx--; 
            if(map.count({inx,iny}))return true;
            map[{inx,iny}] = true;
        }
        return false;
    }
};