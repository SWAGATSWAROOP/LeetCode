class Solution {
public:
    int mxDP(vector<int>& nums1,vector<int>& nums2,int i,int j,vector<vector<int>>& v){
        if(i >= nums1.size() || j >= nums2.size())return -1e9;
        if(v[i][j] != -1e9+1)return v[i][j];
        int a = mxDP(nums1,nums2,i+1,j+1,v);
        int c = mxDP(nums1,nums2,i+1,j,v);
        int d = mxDP(nums1,nums2,i,j+1,v);
        int k = a == -1e9 ? 0:a;
        int l = nums1[i]*nums2[j];
        int b = l + k;
        b = max(b,l);
        return v[i][j] = max(a,max(b,max(c,d)));
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> v(nums1.size(),vector<int>(nums2.size(),-1e9+1));
        return mxDP(nums1,nums2,0,0,v);
    }
};