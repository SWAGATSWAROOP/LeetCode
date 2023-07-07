const static auto initialize = [] { std::ios::sync_with_stdio(false); 
std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int mx(string& answerKey, int k,int l){
        char s = !l ? 'T' : 'F';
        int index = 0,count = 0,c = 0,z = k;
        while(answerKey[index]==s)index++;
        for(int i = 0;i<answerKey.size();i++){
            if(answerKey[i]!=s){
                count = max(c,count);
                if(!z){
                    c = i - index - 1;
                    index++;
                    while(answerKey[index]==s)index++;
                }
                else z--;
            }
            c++;
        }
        count = max(c,count);
        return count; 
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(mx(answerKey,k,1),mx(answerKey,k,0));
    }
};