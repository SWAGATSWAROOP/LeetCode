// 6. Zigzag Conversion
// Medium
// 5K
// 10.6K
// Companies
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
 

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of English letters (lower-case and upper-case), ',' and '.'.
// 1 <= numRows <= 1000
// Accepted
// 915.9K
// Submissions
// 2.1M
// Acceptance Rate
// 43.5%


//My Solutuion
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size()==1 || s.size() < numRows)return s;
        string a[s.size()];
        int row = 0;
        bool down = true;
        for(int i=0;i<s.size();i++){
            a[row].push_back(s[i]);
            if(row == 0) down = true;
            else if(row == numRows-1) down = false;
            if(down){
                row++;
            }
            else{
                row--;
            }
        }
        string res = "";
        for(int i=0;i<numRows;i++){
            res += a[i];
        }
        return res;
    }
};

//Given Solution
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        bool down=true;
        string arr[numRows];
        int row=0;
        for(int i=0; i<s.size(); i++) {
            arr[row].push_back(s[i]);
            if(row==numRows-1) down=false;
            else if (row==0) down=true;
            if(down) row++;
            else row--;
        }
        string res="";
        for(int i=0; i<numRows; i++) {
            res += arr[i];
        }
        return res;
    }
};