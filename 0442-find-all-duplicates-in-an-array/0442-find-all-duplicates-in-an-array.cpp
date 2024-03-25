class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> s, dup;

        for (auto i : nums) {
            if (s.find(i) != s.end())
                dup.insert(i);
            s.insert(i);
        }

        return vector<int>(dup.begin(), dup.end());
    }
};