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
    vector<int> res;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (!root)
            return {};
        res.clear();
        int index = 0;
        if (!TravelTree(root, voyage, index))
            return {-1};
        return res;
    }

    bool TravelTree(TreeNode* root, vector<int>& voyage, int& index) {
        if (!root)
            return true;
        if (index >= voyage.size()) {
            return root == NULL;
        }
        
        if (root->val != voyage[index])
            return false;
        // root->val == voyage[index]
        index++;
        bool isMatched = TravelTree(root->left, voyage, index) && TravelTree(root->right, voyage, index);
        if (!isMatched) {
            res.push_back(root->val);
            isMatched = TravelTree(root->right, voyage, index) && TravelTree(root->left, voyage, index);
        }
        return isMatched;
    }
};