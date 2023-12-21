class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size(),diff = 0;
        for(int i = 1;i<n;i++){
            diff = max(diff,(points[i][0] - points[i-1][0]));
        }
        return diff;
    }
};