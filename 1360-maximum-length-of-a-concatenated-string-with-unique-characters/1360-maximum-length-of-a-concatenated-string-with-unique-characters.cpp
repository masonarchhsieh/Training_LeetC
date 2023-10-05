class Solution {
    static bool compare(const string &s1, const string &s2) {
        return s1.length() >= s2.length();
    }

public:
    int maxLength(vector<string>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return helper(arr, 0, {});
    }

    int helper(vector<string>& arr, int idx, unordered_set<char> s) {
        if (idx >= arr.size())
            return s.size();

        bool canAdd = true;
        unordered_set<char> _s = s;
        for (auto i = 0; i < arr[idx].length(); i++) {
            if (_s.find(arr[idx][i]) != _s.end()) {
                canAdd = false;
                break;
            }
            _s.insert(arr[idx][i]);
        }
        if (canAdd) {
            return max(helper(arr, idx + 1, _s), helper(arr, idx + 1, s));
        }
        
        return max(helper(arr, idx + 1, s), helper(arr, idx + 2, s));
    }
};