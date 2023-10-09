class Solution {
public:
    int minPartitions(string n) {
        bool resolved = true;
        for (size_t i = 0; i < size(n); i++) {
            if (n[i] == '0')
                continue;
            n[i] = n[i] - 1;
            resolved = false;
        }
        if (resolved)
            return 0;
        return 1 + minPartitions(n);
    }
};