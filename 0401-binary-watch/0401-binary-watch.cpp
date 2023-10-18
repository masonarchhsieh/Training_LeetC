class Solution {
    const int hours[4] = { 1, 2, 4, 8 };
    const int minutes[6] = { 1, 2, 4, 8, 16, 32 };
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> combinations;
        helper(combinations, 0, 0, 0, turnedOn);
        return combinations;
    }

    void helper(vector<string>& combinations, int hr, int min, int i, int turnedOn) {
        if (turnedOn == 0) {
            std::string s = std::to_string(hr) + (min < 10? ":0" : ":") + to_string(min);
            combinations.push_back(s);
            return;
        }
        
        for (auto j = i; j < size(hours) + size(minutes); j++) {
            // hours
            if (j < size(hours)) {
                hr += hours[j];
                if (hr < 12)
                    helper(combinations, hr, min, j + 1, turnedOn - 1);
                
                hr -= hours[j];
            } 
            // minutes
            else {
                min += minutes[j - size(hours)];
                if (min < 60)
                    helper(combinations, hr, min, j + 1, turnedOn - 1);
                min -= minutes[j - size(hours)];
            }
        }
    }
};