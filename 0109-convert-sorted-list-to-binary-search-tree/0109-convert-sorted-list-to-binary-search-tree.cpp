/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
// https://www.geeksforgeeks.org/insertion-in-an-avl-tree/
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = NULL;

        while (head) {
            root = insert(root, head->val);
            head = head->next;
        }

        return root;
    }

    TreeNode* insert(TreeNode* node, int value) {
        if (!node)
            return new TreeNode(value);
        if (value < node->val)
            node->left = insert(node->left, value);
        else if (value > node->val)
            node->right = insert(node->right, value);
        else
            return node;
        int balance = getBalance(node);
        // left left
        if (balance > 1 && value < node->left->val)
            return rightRotate(node);
        // right right
        if (balance < -1 && value > node->right->val)
            return leftRotate(node);
        // left right
        if (balance > 1 && value > node->left->val) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // right left
        if (balance < -1 && value < node->right->val) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    int getBalance(TreeNode *root) {
        if (!root)
            return 0;
        return Height(root->left) - Height(root->right);
    }
    int Height(TreeNode *root) {
        if (!root)
            return 0;
        return 1 + max(Height(root->left), Height(root->right));
    }

    TreeNode* rightRotate(TreeNode* node) {
        TreeNode* l_node = node->left;
        TreeNode* lr_node = l_node->right;

        //perform rotation
        l_node->right = node;
        node->left = lr_node;

        return l_node;
    }
    
    TreeNode* leftRotate(TreeNode* node) {
        TreeNode* r_node = node->right;
        TreeNode* rl_node = r_node->left;

        //perform rotation
        r_node->left = node;
        node->right = rl_node;

        return r_node;
    }
    
};