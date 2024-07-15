/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> childs;
        unordered_map<int, TreeNode*> m;
        TreeNode *root;

        for (auto description : descriptions) {
            TreeNode *parent, *child;
            childs.insert(description[1]);
            if (m.find(description.front()) == m.end()) {
                m[description.front()]= new TreeNode(description.front()); 
            } 
            parent = m[description.front()];
            
            if (m.find(description[1]) == m.end()) {
                m[description[1]] = new TreeNode(description[1]); 
            }
            child = m[description[1]];

            if (description.back()) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }

        auto it = (std::find_if(m.begin(), m.end(), [childs](const std::pair<int, TreeNode*> &p){ 
            return childs.find(p.first) == childs.end(); }));
        return (*it).second;
    }
};