class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(begin(skill), end(skill));
        long long equal = skill.front() + skill.back();
        long long res = 0ll;
        for (auto i = 0; i < size(skill) / 2; i++) {
            if (skill.at(i) + skill.at(size(skill) - 1 - i) != equal)
                return -1;
            res += (skill.at(i) * skill.at(size(skill) - 1 - i));
        }

        return res;
    }
};