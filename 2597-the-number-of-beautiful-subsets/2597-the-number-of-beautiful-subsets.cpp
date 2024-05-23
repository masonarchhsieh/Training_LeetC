class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> visited;
        backtrack(nums, k, 0, visited, res);

        return res - 1;     // subtract the empty set
    } 

    void backtrack(vector<int> &nums, int k, int index, unordered_map<int, int> &visited, int &count) {
        if (index == size(nums)) {
            count++;
            return;
        }

        int num = nums[index];
        if (visited.find(num - k) == visited.end() && visited.find(num + k) == visited.end()) {
            visited[num]++;
            backtrack(nums, k, index + 1, visited, count);
            visited[num]--;
            if (visited[num] == 0)
                visited.erase(num);
        }

        backtrack(nums, k, index + 1, visited, count);
    }
};