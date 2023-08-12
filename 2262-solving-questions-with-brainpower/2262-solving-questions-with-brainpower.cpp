class Solution {
public:
    long long mP(vector<vector<int>>& questions,int i,vector<long long>& v){
        if(i >= questions.size())return 0;
        if(v[i])return v[i];
        long long take = questions[i][0] + mP(questions,i+questions[i][1]+1,v);
        long long notake = mP(questions,i+1,v);
        return v[i] = max(take,notake);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> q(questions.size(),0);
        return mP(questions,0,q);
    }
};