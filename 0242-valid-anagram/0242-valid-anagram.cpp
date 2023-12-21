#include<unordered_map>
class Solution {
public:
    bool isAnagram(string a, string b) {
        if(a.length()!=b.length()){
        return false;
    }
    unordered_map<char,int> map;
    for(int i=0;i<a.length();i++){
        map[a[i]]++;
    }
    for(int i = 0;i<b.length();i++){
        if(map.count(b[i])>0 && map[b[i]]>0){
            map[b[i]]--;
            continue;
        } 
        else{
        	return false;
        }
    }
    return true;
    }
};