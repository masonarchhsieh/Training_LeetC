// https://leetcode.com/problems/decode-the-message

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> m;
        int idx = 0;
        for (auto i = 0; i < key.length(); i++) {
            if (!isspace(key[i]) && m.find(key[i]) == m.end()) {
                m[key[i]] = 'a' + idx++;
            }
        }

        for (auto i = 0; i < message.length(); i++) {
            if (!isspace(message[i]))
                message[i] = m[message[i]];
        }

        return message;
    }
};