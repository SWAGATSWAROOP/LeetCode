class Solution {
public:
    bool isValid(string s,int length){
        if(length > 3 || !length || (length == 3 && s[0] > '2') ||(length > 1 && s[0] == '0'))return false;
        if(length == 3 && s[0] == '2' && (s[1] > '5' || (s[1] == '5' && s[2] > '5')))return false;
        return true;
    }

    void restoreIpAddresses(string s,vector<string>& v,int count,int index){
        if(!count){
            cout<<s<<endl;
            if(isValid(s.substr(index),s.size()-index)){
                v.push_back(s);
            }
            cout<<endl;
            return;
        }
        for(int i = 1;i<=3 && index+i<s.size();i++){
            if(isValid(s.substr(index,i),i)){
                s.insert(index+i,".");
                restoreIpAddresses(s,v,count-1,index+i+1);
                s.erase(index+i,1);
            }
            else break;
        }
        return;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        if(s.size() < 4 || s.size() > 12)return v;
        restoreIpAddresses(s,v,3,0);
        return v;
    }
};