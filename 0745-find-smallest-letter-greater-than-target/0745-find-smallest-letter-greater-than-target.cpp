class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = 0,j = letters.size()-1;
        while(i<j){
            int mid = i+(j-i)/2;
            if(letters[mid] == target){
                while(mid < letters.size() && letters[mid] == target)mid++;
                if(mid == letters.size())return letters[0];
                return letters[mid];
            }
            else if(letters[mid] > target)j = mid - 1;
            else i = mid + 1;
        }
        if(letters[i] > target)return letters[i];
        while(i<letters.size() && letters[i] <= target)i++;
        return i == letters.size() ? letters[0]:letters[i];

    }
};