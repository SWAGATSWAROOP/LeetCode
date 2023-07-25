class Solution {
public:
    string minWindow(string s, string t) {
        string g = "";
        unordered_map<char,int> map;
        unordered_map<char,int> mp;
        for(int i = 0;i<t.size();i++)map[t[i]]++;
        int i = 0,len = 1e6,z = 1e6;
        while(i<s.size() && !map.count(s[i]))i++;
        int j = i;
        while(j < s.size()){
            while(map.size() == mp.size()){
                bool flag = true;
                for(auto x:mp){
                    if(x.second < map[x.first]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    z = j - i;
                    if(z <= len){
                        g = s.substr(i,z);
                        len = z;
                    }
                    mp[s[i]]--;
                    i++;
                    while(i<s.size() && !map.count(s[i]))i++;
                }
                else break;
            }
            if(map.count(s[j]))mp[s[j]]++;
            if(mp.size()==1){
                bool flag = false;
                for(auto x:mp){
                    if(x.second > map[x.first]){
                        mp[s[i]]--;
                        i++;
                        while(i<s.size() && !map.count(s[i]))i++;
                    }
                }
            }
            j++;
        }
        while(map.size() == mp.size()){
                bool flag = true;
                for(auto x:mp){
                    if(x.second < map[x.first]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    z = j - i;
                    if(z < len){
                        g = s.substr(i,z);
                        len = z;
                    }
                }
                mp[s[i]]--;
                i++;
                while(i<s.size() && !map.count(s[i]))i++;
        }
        return g;
    }
};