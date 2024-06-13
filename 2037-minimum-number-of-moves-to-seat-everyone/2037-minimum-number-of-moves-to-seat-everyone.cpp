class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(begin(seats), end(seats));
        sort(begin(students), end(students));
        int moves = 0;

        for (auto i = 0; i < size(seats); i++) {
            moves += abs(students[i] - seats[i]);
        }
        
        return moves;
    }
};