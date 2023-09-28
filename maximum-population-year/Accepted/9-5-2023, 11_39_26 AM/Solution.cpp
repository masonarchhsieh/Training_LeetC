// https://leetcode.com/problems/maximum-population-year

bool compare(const pair<int, int>&a, const pair<int, int>&b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        unordered_map<int, int> m;

        for (auto i : logs)
            for (auto j = i[0]; j < i[1]; j++)
                m[j]++;

        return max_element(m.begin(), m.end(), compare)->first;
    }
};