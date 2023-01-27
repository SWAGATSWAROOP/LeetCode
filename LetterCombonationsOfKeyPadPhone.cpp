// 17. Letter Combinations of a Phone Number
// Medium
// 13.9K
// 806
// Companies
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].
// Accepted
// 1.5M
// Submissions
// 2.6M
// Acceptance Rate
// 56.1%

class Solution {
public: 
    void letter(vector<string>& v,string digits,unordered_map<char,string>& map){
        if(digits.length() == 1){
            string o = map[digits[0]];
            int l = o.length();
            for(int i=0;i<l;i++){
                v.push_back("");
                v[i] += o[i]; 
            }
            return;
        }
        letter(v,digits.substr(1),map);
        int k = v.size();
        int l = map[digits[0]].length();
        for(int i = 1;i<l;i++){
            for(int j = 0;j<k;j++){
                v.push_back(v[j]);
            }
        }
        for(int i=0;i<l;i++){
            for(int j=0;j<k;j++){
                v[k*i + j] = map[digits[0]][i] + v[j+i*k];
            }
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if(digits.length()==0){
            return v;
        }
        unordered_map<char,string> map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        letter(v,digits,map);
        return v;
    }
};