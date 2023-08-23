class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        if(n == 1)return s;
        int i = 1;
        while(i<n){
            if(s[i] == s[i-1]){
                int j = i+1;
                while(j < n){
                    if(s[i]!=s[j]){
                        swap(s[i],s[j]);
                        break;
                    }
                    j++;
                }
                if(j == n){
                    cout<<"SWAG "<<i<<endl;
                    string m = "";
                    m += s[i];
                    s.erase(i,1);
                    if(s[0] == m[0]){
                        int k = 1;
                        while(k < s.size()){
                            cout<<"YES"<<endl;
                            if(s[k-1] != m[0] && s[k] != m[0]){
                                cout<<"YES"<<endl;
                                s.insert(k,m);
                                break;
                            }
                            k++;
                        }
                        if(k == s.size())return "";
                    }
                    else s = m + s;
                }
                else i++;
            }
            else i++;
        }
        // bool m = true;
        // for(int i = 1;i<n;i++){
        //     if(s[i] == s[i-1]){
        //         m = false;
        //         break;
        //     }
        // }
        return s;
    }
};