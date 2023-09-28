// https://leetcode.com/problems/baseball-game

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        stringstream ss; 
        int operations_int;

        int prev = 0;
        cout << "ops size: " << operations.size() << endl;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "C") {
                record.pop_back();
            }
            else if (operations[i] == "D") {
                if (!record.empty())
                    record.push_back(record[record.size() - 1] * 2);
            }
            else if (operations[i] == "+") {
                record.push_back(record[record.size() -1] + record[record.size() - 2]);
                
            }
            else {
                int tmp = stoi(operations[i]);
                record.push_back(tmp);
            }
        }
        if (record.empty())
            return 0;
        for (auto i = 1; i < record.size(); i++) {
            record[i] += record[i-1];
        }

        return record[record.size() - 1];
    }
};