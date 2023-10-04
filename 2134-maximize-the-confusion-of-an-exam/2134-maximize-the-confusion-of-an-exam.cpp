class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int maxConsecutive = 0;
        int maxCount = 0;
        int l = 0;
        int counts[2] = { 0 }; // 0: F, 1: T

        for (auto r = 0; r < n; r++) {
            counts[answerKey[r] == 'T']++;
            maxCount = max(maxCount, counts[answerKey[r] == 'T']);
            while (r - l + 1 - maxCount > k) {
                counts[answerKey[l] == 'T']--;
                l++;
            }
            maxConsecutive = max(maxConsecutive, r - l + 1);
        }

        return maxConsecutive;
    }
};