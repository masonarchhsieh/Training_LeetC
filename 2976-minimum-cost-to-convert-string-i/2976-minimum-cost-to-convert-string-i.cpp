class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        assert(size(original) == size(changed) && size(changed) == size(cost));
        assert(source.length() == target.length());
        const int inf = 1 << 29;
        int cost_dict[26][26];

        for (int i = 0; i < 26; i++) {
            fill(begin(cost_dict[i]), end(cost_dict[i]), inf);
            cost_dict[i][i] = 0;
        }

        for (auto i = 0; i < size(cost); i++)
            cost_dict[original[i] - 'a'][changed[i] - 'a'] = min(cost_dict[original[i] - 'a'][changed[i] - 'a'], cost[i]);

        for (auto i = 0; i < 26; i++)
            for (auto j = 0; j < 26; j++)
                for (auto k = 0; k < 26; k++) 
                    cost_dict[j][k] = min(cost_dict[j][k], cost_dict[j][i] + cost_dict[i][k]);

        long long res = 0;
        int n = source.length();
        for (auto i = 0; i < n; i++) {
            if (source[i] == target[i])
                continue;
            if (cost_dict[source[i] - 'a'][target[i] - 'a'] >= inf)
                return -1;
            res += cost_dict[source[i] - 'a'][target[i] - 'a'];
        }

        return res;
    }
};