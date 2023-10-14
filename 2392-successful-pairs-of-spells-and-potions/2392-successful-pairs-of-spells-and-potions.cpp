class Solution {
public:
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        for(int i = 0;i<spells.size();i++){
            double s = (1.0*success)/spells.at(i);
            int index = lower_bound(potions.begin(),potions.end(),s) - potions.begin();
            spells.at(i) = potions.size() - index;
        }
        return spells;
    }
};