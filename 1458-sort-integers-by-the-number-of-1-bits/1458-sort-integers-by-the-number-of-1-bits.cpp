class Solution {
public:
    static int nosetBits(int n){
        if(n == 0)return 0;
        return 1+nosetBits(n & (n-1));
    }

    static bool comp(int a,int b){
        int x = nosetBits(a);
        int y = nosetBits(b);
        if(x == y)return a < b;
        return x < y ? true:false;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};