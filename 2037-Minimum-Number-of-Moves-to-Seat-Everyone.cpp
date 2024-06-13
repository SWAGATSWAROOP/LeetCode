class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int moves = 0,n = seats.size();
        for(int i = 0;i < n;i++){
            moves += abs(seats[i]-students[i]);
        }
        return moves;
    }
};