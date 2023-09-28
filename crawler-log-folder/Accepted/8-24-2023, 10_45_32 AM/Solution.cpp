// https://leetcode.com/problems/crawler-log-folder

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for (auto i = 0; i < logs.size(); i++) {
            if (logs[i] == "../") {
                if (level > 0)
                    level--;
            }
            else if (logs[i] == "./") {
                // do nothing
            }
            else
                level++;
        }

        return level;
    }
};