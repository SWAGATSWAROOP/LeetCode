class Solution {
public:
    pair<int,int> w(vector<int>& nums,int i,int j,int turn){
        if(i > j)return {0,0};
        if(turn){
            pair<int,int> s = w(nums,i+1,j,0);
            pair<int,int> k = w(nums,i,j-1,0);
            s.second += nums[i];
            k.second += nums[j];
            pair<int,int> z;
            if(s.second > k.second)return s;
            if(s.second < k.second)return k;
            return s.first >= k.first ? s:k;
        }
        pair<int,int> s = w(nums,i+1,j,1);
        pair<int,int> k = w(nums,i,j-1,1);
        s.first += nums[i];
        k.first += nums[j];
        pair<int,int> z;
        if(s.first > k.first)return s;
        if(s.first < k.first)return k;
        return s.second >= k.second ? s:k;
    }

    bool PredictTheWinner(vector<int>& nums) {
        pair<int,int> s = w(nums,1,nums.size()-1,0);
        pair<int,int> k = w(nums,0,nums.size()-2,0);
        s.second += nums[0];
        k.second += nums[nums.size()-1];
        return s.second >= s.first || k.second >= k.first;
    }
};