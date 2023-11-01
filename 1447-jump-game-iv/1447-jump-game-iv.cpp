class Solution {
public:
    int minJumps(vector<int>& arr) {
        if (size(arr) == 1)
            return 0;
        if (arr.front() == arr.back())
            return 1;
        unordered_map<int, vector<int>> m;
        for (int i = size(arr) - 1; i >= 0; i--)
            m[arr[i]].push_back(i);

        return helper(arr, m);
    }

    int helper(vector<int>& arr, unordered_map<int, vector<int>> m) {
        vector<bool> visited(size(arr), false);
        queue<int> q;
        int n = size(arr);

        q.push(0);
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size-- > 0) {
                int i = q.front();
                q.pop();

                visited[i] = true;
                if (i == n - 1)
                    return steps;
                int val = arr[i];
                for (auto &j : m[val]) {
                    if (i == j || visited[j])
                        continue;
                    q.push(j);
                }

                m[val].clear();
                if (i - 1 >= 0 && !visited[i - 1])
                    q.push(i - 1);
                if (i + 1 < n && !visited[i + 1])
                    q.push(i + 1);
            }
            steps++;
        }
        return -1;
    }

};