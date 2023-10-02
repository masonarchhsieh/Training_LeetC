class Solution {
    vector<int> v;
    vector<int> res;
public:
    vector<int> pathInZigZagTree(int label) {
        v.clear();
        buildTree(1, label);
        findPath(label);
        return res;
    }
    
    void buildTree(int start, const int label) {
        int level = 0;
        int nodes_in_level = pow(2, level), cur_nodes_in_level = 0;
        auto i = 1;
        while (i <= label) {
            for (cur_nodes_in_level = 0; cur_nodes_in_level < pow(2, level); cur_nodes_in_level++) {
                v.push_back(i + cur_nodes_in_level);  
            }
            if (level % 2 == 1) {
                reverse(v.end() - cur_nodes_in_level, v.end());
            }
            level++;
            i += cur_nodes_in_level;
        }
    }

    void findPath(int label) {
        int pos = find(v.begin(), v.end(), label) - v.begin();
        while (pos > 0) {
            res.push_back(v.at(pos));
            pos = (pos - 1) / 2;
        }
        res.push_back(v.at(pos));           // v[0]
        reverse(res.begin(), res.end());    // reverse the list
    }
};