class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        std::sort(std::begin(cookies), std::end(cookies));
        std::vector<int> distributed(k, 0);
        int res = INT_MAX;
        helper(cookies, distributed, 0, k, res);
        return res;
    }

    void helper(std::vector<int>& cookies, std::vector<int>& distributed, int index, int k, int& res) {
        if (index == std::size(cookies)) {
            int _max = 0;
            for (auto i : distributed)
                _max = std::max(_max, i);
            res = std::min(res, _max);
            return;
        }

        if (*std::max_element(std::begin(distributed), std::end(distributed)) >= res)
            return;

        for (auto i = 0; i < k; i++) {
            distributed[i] += cookies.at(index);
            helper(cookies, distributed, index + 1, k, res);
            distributed[i] -= cookies.at(index);
            if (distributed[i] == 0)
                return;
        }
    }
};