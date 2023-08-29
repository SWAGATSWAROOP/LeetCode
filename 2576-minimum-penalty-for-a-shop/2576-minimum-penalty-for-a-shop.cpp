class Solution {
public:
    int bestClosingTime(string customers) {
        int penality = customers.size();
        int p = penality;
        int ans = 0,countY = 0;
        int n = customers.size()-1;
        for(int i = 0;i<=n;i++){
            penality -= countY;
            cout<<penality<<endl;
            if(p > penality || (i == n && p == penality && customers[n] == 'Y')){
                ans = i;
                p = penality;
            }
            if(customers[i] == 'Y')countY = 1;
            else {
                penality++;
                countY = 0;
            }
        }
        if(ans == n && customers[n] == 'Y')ans++;
        return ans;
    }
};