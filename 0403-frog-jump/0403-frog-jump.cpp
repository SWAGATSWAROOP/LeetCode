class Solution {
public:
    int bs(vector<int>& stones,int s,int tar){
        int e = stones.size()-1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(stones[mid] > tar)e = mid - 1;
            else if(stones[mid] < tar)s = mid + 1;
            else return mid;
        }
        return 0;
    }

    bool Cross(vector<int>& stones,int i,int k,vector<vector<int>>& v){
        if(stones.size()-1 <= i)return true;
        if(v[i][k] != -1)return v[i][k];
        int a = stones[i] + k - 1;
        int b = stones[i] + k;
        int c = stones[i] + k + 1;
        int x = bs(stones,i+1,a);
        int y = bs(stones,i+1,b);
        int z = bs(stones,i+1,c);
        bool d = x ? Cross(stones,x,k-1,v):false;
        bool e = y ? Cross(stones,y,k,v):false;
        bool f = z ? Cross(stones,z,k+1,v):false;
        return v[i][k] = d || e || f;
    }

    bool canCross(vector<int>& stones) {
        if(stones[1] != 1)return false;
        vector<vector<int>> v(stones.size(),vector<int>(stones.size()+1,-1));
        return Cross(stones,1,1,v);
    }
};