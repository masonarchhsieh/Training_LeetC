class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<long long>> m;
        vector<long long> res(arr.size(), 0);

        for (auto i = 0; i < size(arr); i++)
            m[arr.at(i)].push_back(i);

        for (auto i : m) {
            long long prefix_sum = 0;
            long long sum = accumulate(i.second.begin(), i.second.end(), 0ll);
            for (auto j = 0; j < size(i.second); j++) {
                res[i.second.at(j)] = (long long) abs(j * i.second.at(j) - prefix_sum) + (sum - prefix_sum -  i.second.at(j) * (size(i.second) - j));
                prefix_sum += i.second.at(j);
            }
        }

        return res;
    }
};