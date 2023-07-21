//91. Decode Ways

//Recusion
class Solution {
public:
    int numDecodings(string& s,int index = 0) {
        if(index == s.size())return 1;
        if(s[index] == '0')return 0;
        int m = numDecodings(s,index+1);
        int n = 0;
        if(index+1 < s.size()){
            int l = s[index+1] - 48;
            int z = s[index] - 48;
            if((z == 2 && l >= 7) || z > 2)return m;
            n = numDecodings(s,index+2);
        }
        return m+n;
    }
};

//Memotization

class Solution {
public:
    int numD(string& s,int index,vector<int>& v){
        if(index == s.size())return 1;
        if(v[index]!=-1)return v[index];
        if(s[index] == '0')return v[index] = 0;
        int m = numD(s,index+1,v);
        int n = 0;
        if(index+1 < s.size()){
            int l = s[index+1] - 48;
            int z = s[index] - 48;
            if((z == 2 && l >= 7) || z > 2)return m;
            n = numD(s,index+2,v);
        }
        return v[index] = m+n;
    }

    int numDecodings(string& s){
        vector<int> v(s.size(),-1);
        return numD(s,0,v);
    }
};


//Tabulation

const static auto initialize = [] { std::ios::sync_with_stdio(false); 
std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int numDecodings(string& s){
        vector<int> v(s.size()+1);
        v[s.size()] = 1;
        v[s.size()-1] = s[s.size()-1] == '0' ? 0:1;
        for(int i = s.size()-2;i>=0;i--){
            if(s[i] == '0')v[i] = 0;
            else{
                v[i] = v[i+1];
                int l = s[i+1] - 48;
                int z = s[i] - 48;
                if((z == 2 && l >= 7) || z > 2)continue;
                v[i] += v[i+2];
            }
        }
        return v[0];
    }
};

//With Space Optimization
const static auto initialize = [] { std::ios::sync_with_stdio(false); 
std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int numDecodings(string& s){
        int nextn = 1;
        int next = s[s.size()-1] == '0' ? 0:1;
        for(int i = s.size()-2;i>=0;i--){
            if(s[i] == '0'){
                nextn = next;
                next = 0;
            }
            else{
                int o = next;
                int l = s[i+1] - 48;
                int z = s[i] - 48;
                if((z == 2 && l >= 7) || z > 2){
                    nextn = next;
                    continue;
                }
                o += nextn;
                nextn = next;
                next = o;
            }
        }
        return next;
    }
};