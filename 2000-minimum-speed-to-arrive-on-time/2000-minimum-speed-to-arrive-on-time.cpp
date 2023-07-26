class Solution {
public:
    bool valid(vector<int>& dist,int speed,double hour){
        double hoursum = 0;
        for(int i = 0;i<dist.size()-1;i++){
            hoursum += ceil((1.0*dist[i])/speed);
        }
        hoursum += (1.0*dist[dist.size()-1])/speed;
        return hoursum <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(dist.size()-1 > hour)return -1;
        int ans = -1;
        int i = 1,j = 1e7;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(valid(dist,mid,hour)){
                ans = mid;
                cout<<ans<<endl;
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        return ans;
    }
};