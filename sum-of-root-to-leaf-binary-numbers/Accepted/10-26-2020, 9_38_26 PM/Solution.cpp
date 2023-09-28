// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers

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
    int sumRootToLeaf(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        vector<string> ttls;
        helper(root, ttls, "");
        
        int sum = 0;
        for (int i=0; i<ttls.size(); i++) {
            sum += convertBinToInt(ttls[i]);
        }
        
        return sum;
    }
    
    int convertBinToInt(string binary) {       
        int res = 0;
        int itr = 0;
        while (itr < binary.length()) {
            if (binary[binary.length()-1-itr] == '1')
                res = pow(2, itr) + res;
            itr++;
        }
        
        return res;
    }
    
    void helper(TreeNode* root, vector<string>& ttls, string prev) {
        if (root == NULL)
            return;
        else
            prev = prev + to_string(root->val);

        if (root->left == NULL && root->right == NULL)
            ttls.push_back(prev);
        else {

            helper(root->left, ttls, prev);
            helper(root->right, ttls, prev);
        }
    }
};