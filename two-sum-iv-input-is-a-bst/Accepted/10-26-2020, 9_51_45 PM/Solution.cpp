// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
   vector<int> v;
    
    void buildvector(TreeNode* root){
        if(root==NULL){
            return;
        }
        buildvector(root->left);
        v.push_back(root->val);
        buildvector(root->right);
    }
    
    
    
    bool findTarget(TreeNode* root, int k) {
        buildvector(root);
        int left=0,right=v.size()-1;
        while(left!=right){
            int t = v[left]+v[right];
            if(t==k){
                return true;
                break;
            }
            else if(t>k){
                right--;
            }
            else if(t<k){
                left++;
            }
        }
        return false;
        
        
        
        return true;
        
        
    }
};