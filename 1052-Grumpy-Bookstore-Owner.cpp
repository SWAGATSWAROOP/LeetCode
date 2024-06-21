class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0,n = grumpy.size();
        for(int i = 0;i < n;i++){
            if(!grumpy[i])sum += customers[i];
        }
        int j = 0,i = 0;
        while(j < minutes){
            if(grumpy[j])sum += customers[j];
            j++;
        }
        int mxsum = sum;
        while(j < n){
            if(grumpy[i])sum -= customers[i];
            if(grumpy[j])sum += customers[j];
            mxsum = max(mxsum,sum);
            i++;
            j++;
        }
        return mxsum;
    }
};