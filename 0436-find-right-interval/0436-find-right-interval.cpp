class Solution {
public:
    static bool comp(pair<int,int> p1,pair<int,int> p2){
        return p1.first<p2.first;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int,int>> v;
        vector<int> q;
        for(int i = 0;i<intervals.size();i++){
            pair<int,int> p = {intervals[i][0],i};
            v.push_back(p);
        }
        sort(v.begin(),v.end(),comp);
        for(int k = 0;k<intervals.size();k++){
            int target = intervals[k][1];
            int i = 0,j = intervals.size()-1;
            while(i < j){
                int mid = i + (j-i)/2;
                cout<<mid<<endl;
                if(v[mid].first == target){
                    q.push_back(v[mid].second);
                    break;
                }
                else if(v[mid].first < target)i = mid+1;
                else j = mid-1;
            }
            if(i == j){
                bool flag = true;
                while(i < intervals.size()){
                    if(v[i].first >= target){
                        q.push_back(v[i].second);
                        flag = false;
                        break;
                    }
                    i++;
                }
                if(flag)q.push_back(-1);
            }
        }
        return q;
    }
};