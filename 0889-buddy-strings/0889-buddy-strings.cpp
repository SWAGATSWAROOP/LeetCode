class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())return 0;
        vector<int> arr(26,0);
        vector<int> arr2(26,0);
        int count = 0,mx = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]!=goal[i])count++;
            arr[s[i]-97]++;
            arr2[goal[i]-97]++;
        }
        for(int i = 0;i<26;i++){
            if(arr[i]!=arr2[i])return false;
            mx = max(arr[i],mx);
        }
        if(count == 2 || (count<=2 && mx >=2))return true;
        return false;
    }
};