class Solution {
public:
    int multiply(char num1,char num2){
        int x = num1 - '0';
        int z = num2 - '0';
        return x*z;
    }

    void add(string& ans,string& z,int k){
        int i = ans.size()-k,j = z.size()-1;
        int carry = 0;
        while(i >=0 && j >= 0){
            int x = ans[i] - '0' + z[j] - '0' + carry;
            carry = x >= 10 ? 1:0;
            ans[i] = '0' + x%10;
            i--;
            j--;
        }
        cout<<ans<<endl;
        while(j >= 0){
            int x = z[j] - '0' + carry;
            carry = x >= 10 ? 1:0;
            ans = char('0' + x%10) + ans;
            j--;
        }
        cout<<ans<<endl;
        if(carry)ans = "1" + ans;
        cout<<ans<<endl;
        return;
    }

    string multiply(string num1, string num2) {
        string ans = "";
        string z;
        int l = num2.size()-1,m = num1.size()-1,c = 0,o;
        for(int j = l;j >= 0;j--){
            o = multiply(num1[m],num2[j]) + c;
            c = o/10;
            ans = char(o%10 + '0') +  ans;
        }
        if(c)ans = char(c + '0') + ans;
        for(int i = m-1;i>=0;i--){
            z = "";
            c = 0;
            for(int j = l;j >= 0;j--){
                o = multiply(num1[i],num2[j]) + c;
                c = o/10;
                z = char(o%10 + '0') +  z;
            }
            if(c)z = char(c + '0') + z;
            add(ans,z,m-i+1);
        }
        if(ans[0] == '0')return "0";
        return ans;
    }
};