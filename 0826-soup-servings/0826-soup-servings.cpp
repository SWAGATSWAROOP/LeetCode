class Solution {
public:
    double sS(int An,int Bn,unordered_map<int,unordered_map<int,double>>& v){
        if(An <= 0 && Bn <= 0)return 0.5;
        else if(An <= 0 || An >= 4800 || Bn >= 4800)return 1;
        else if(Bn <= 0)return 0;
        if(v.count(An) && v[An].count(Bn))return v[An][Bn];
        double a = 0.25*sS(An-100,Bn,v);
        double b = 0.25*sS(An-75,Bn-25,v);
        double c = 0.25*sS(An-50,Bn-50,v);
        double d = 0.25*sS(An-25,Bn-75,v);
        return v[An][Bn] = (a+b+c+d);
    }

    double soupServings(int n) {
        unordered_map<int,unordered_map<int,double>> v;
        return sS(n,n,v);
    }
};