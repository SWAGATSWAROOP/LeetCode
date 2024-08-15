class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> map = {{5,0},{10,0},{20,0}};
        int size = bills.size();

        for(int i = 0;i < size;i++){
            if(bills[i] == 20){
                if(map[10] && map[5]){
                    map[5]--;
                    map[10]--;
                }
                else if(map[5] >= 3){
                    map[5] -= 3;
                }
                else return false;
            }
            else if(bills[i] == 10){
                if(map[5])map[5]--;
                else return false;
            }
            map[bills[i]]++;
        }
        return true;
    }
};