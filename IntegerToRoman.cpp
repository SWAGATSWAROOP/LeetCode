// 12. Integer to Roman
// Medium
// 5.1K
// 5K
// Companies
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral.

 

// Example 1:

// Input: num = 3
// Output: "III"
// Explanation: 3 is represented as 3 ones.
// Example 2:

// Input: num = 58
// Output: "LVIII"
// Explanation: L = 50, V = 5, III = 3.
// Example 3:

// Input: num = 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

// Constraints:

// 1 <= num <= 3999
// Accepted
// 927.2K
// Submissions
// 1.5M
// Acceptance Rate
// 61.7%

#include<vector>
class Solution {
public:
    vector<int>* noofdigits(int num){
        vector<int>* v = new vector<int>(4,0);
        int i = 3;
        while(num){
            int a = num%10;
            num /= 10;
            v->at(i) = a;
            i--;
        }
        return v;
    }

    string intToRoman(int num) {
        vector<int>* v = noofdigits(num);
        string a = "";
        for(int i = 0;i<4;i++){
            if(v->at(i) == 0) continue;
            switch(i){
                case 0:
                for(int i = 0;i<v->at(0);i++){
                    a += 'M';
                }
                break;

                case 1:
                if(v->at(1) == 4){
                    a += "CD";
                }
                else if(v->at(1) == 9){
                    a += "CM";
                }
                else{
                    int x = v->at(1) - 5;
                    int l = x >= 0 ? x:v->at(1);
                    if(l == x){
                       a += "D";
                    }
                    for(int i = 0;i<l;i++){
                        a += "C";
                    }
                }
                break;

                case 2:
                if(v->at(2) == 4){
                    a += "XL";
                }
                else if(v->at(2) == 9){
                    a += "XC";
                }
                else{
                    int x = v->at(2) - 5;
                    int l = x >= 0 ? x:v->at(2);
                    if(l == x){
                       a += "L"; 
                    }
                    for(int i = 0;i<l;i++){
                        a += "X";
                    }
                }
                break;

                case 3:
                if(v->at(3) == 4){
                    a += "IV";
                }
                else if(v->at(3) == 9){
                    a += "IX";
                }
                else{
                    int x = v->at(3) - 5;
                    int l = x >= 0 ? x:v->at(3);
                    if(l == x){
                       a += "V"; 
                    }
                    for(int i = 0;i<l;i++){
                        a += "I";
                    }
                }
                break;
            }
        }
        return a;
    }
};