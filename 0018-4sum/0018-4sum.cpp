class Solution {
public:
    /*
    Time Complexity : O(N^4), Four nested loop creates the time complexity.
    Space Complexity : O(N), Hash Table(set) space.
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> _set;
        if (nums.size() < 4)
            return {};
        for (auto i = 0; i < nums.size() - 3; i++) {
            for (auto j = i + 1; j < nums.size() - 2; j++) {
                for (auto k = j + 1; k < nums.size() - 1; k++) {
                    for (auto l = k + 1; l < nums.size(); l++) {
                        long long tmp = (long long) nums[i] + (long long) nums[j] + (long long) nums[k] + (long long) nums[l];
                        if (tmp == target)
                            _set.insert({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }
        return vector<vector<int>>(_set.begin(), _set.end());
    }
    */

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> _set;
        if (nums.size() < 4)
            return {};

        for (int i = 0; i < nums.size() - 3; i++) {
            for (int j = i + 1; j < nums.size() - 2; j++) {
                long long _target = (long long) target - (long long) nums.at(i) - (long long) nums.at(j);
                int low = j + 1, high = size(nums) - 1;

                while (low < high) {
                    if (nums.at(low) + nums.at(high) < _target)
                        low++;
                    else if (nums.at(low) + nums.at(high) > _target)
                        high--;
                    else {
                        _set.insert({nums.at(i), nums.at(j), nums.at(low), nums.at(high)});
                        low++;
                        high--;
                    }
                
                }
            }
        }

        return vector<vector<int>>(_set.begin(), _set.end());
    }
};