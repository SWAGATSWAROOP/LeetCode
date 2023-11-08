class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy && t == 1)return false;
        int xdist = abs(sx-fx);
        int ydist = abs(sy-fy);
        
        if(xdist == ydist)return xdist <= t;
        if(xdist > ydist){
            return xdist <= t;
        }
        return ydist  <= t;
    }
};