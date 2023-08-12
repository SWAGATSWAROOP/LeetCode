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
        vector<long long> q(questions.size()+1,0);
        for(int i = questions.size()-1;i >= 0;i--){
            long long notake = q[i+1];
            long long take = i + questions[i][1] + 1 < questions.size() ? q[i+questions[i][1]+1] : 0;
            take += questions[i][0];
            q[i] = max(take,notake);
        }
        return q[0];
    }
};