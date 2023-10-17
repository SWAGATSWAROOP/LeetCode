class Solution {
public:
    int findroot(int n,vector<int>& l,vector<int>& r){
        unordered_set<int> set(l.begin(),l.end());
        set.insert(r.begin(),r.end());
        int index = 0,count = 0;
        for(int i = 0;i<n;i++){
            if(set.find(i) == set.end()){
                count++;
                index = i;
            }
        }
        return count == 1 ? index:-1;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        int root = findroot(n,l,r);
        if(root == -1)return false;
        unordered_map<int,int> map;
        queue<int> q;
        q.push(root);
        while(!q.empty()){
            int i = q.front();
            if(map.count(i))return false;
            map[i]++;
            q.pop();
            if(l[i] != -1)q.push(l[i]);
            if(r[i] != -1)q.push(r[i]);
        }
        if(map.size() != n)return false;
        return true;
    }
};