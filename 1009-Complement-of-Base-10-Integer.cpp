class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n)return 1;
        int numberofbits = log2(n)+1;
        cout<<numberofbits<<endl;
        return pow(2,numberofbits) - n - 1;
    }
};