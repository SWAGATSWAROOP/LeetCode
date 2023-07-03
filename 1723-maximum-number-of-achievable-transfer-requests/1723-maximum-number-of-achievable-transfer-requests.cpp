class Solution {
public:
    int l = INT_MIN;
    void R(int n,vector<vector<int>>& r,vector<int>& v,int index,int ans,int m){
        if(index == m){
            for(int i = 0;i<n;i++){
                if(v[i])return;
            }
            l = max(ans,l);
            return;
        }
        v[r[index][0]]--;
        v[r[index][1]]++;
        R(n,r,v,index+1,ans+1,m);
        v[r[index][0]]++;
        v[r[index][1]]--;
        R(n,r,v,index+1,ans,m);
        return;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> v(n,0);
        int m = requests.size();
        R(n,requests,v,0,0,m);
        return l;
    }
};