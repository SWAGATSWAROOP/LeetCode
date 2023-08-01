class Solution {
public:
    void Recurr(vector<vector<int>>& v,vector<int> v1,int index,int k,const int n){
        if(!k){
            v.push_back(v1);
            return;
        }
        if(index > n)return;
        for(int i = index;i<=n;i++){
            v1.push_back(i);
            Recurr(v,v1,i+1,k-1,n);
            v1.pop_back();
        }
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> v;
        vector<int> v1;
        Recurr(v,v1,1,k,n);
        return v;
    }
};