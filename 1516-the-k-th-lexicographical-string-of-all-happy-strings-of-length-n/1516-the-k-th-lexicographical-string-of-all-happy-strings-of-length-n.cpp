class Solution {
    const char happy_string[3] = { 'a', 'b', 'c' };
    vector<string> v;
public:
    string getHappyString(int n, int k) {
        v.clear();
        string res;
        int cnt = 0;
        backtrack(n, cnt, "", res);
        sort(v.begin(), v.end());
        return (cnt >= k)? v.at(k - 1) : "";
    }

    void backtrack(int n, int& cnt, string s, string &res) {
        if (size(s) > 1) {
            if (s[size(s) - 1] == s[size(s) - 2])
                return;
        }
        if (n == 0) {
            if (size(s) > size(res))
                res = s;
            else if (size(s) == size(res))
                res = (s > res)? s : res;
            v.push_back(s);
            cnt++;
            return;
        }
        backtrack(n - 1, cnt, s + 'a', res);
        backtrack(n - 1, cnt, s + 'b', res);
        backtrack(n - 1, cnt, s + 'c', res);
    }
};