class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v;
        v.push_back(0);
        for(int i = 1;i<=n;i++){
            int count = 0;
            int z = i;
            while(z){
                count++;
                z &= (z-1);
            }
            v.push_back(count);
        }
        return v;
    }
};