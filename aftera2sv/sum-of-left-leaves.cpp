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
    int recursive(TreeNode* root, bool left){
        if(root == nullptr) return 0;
        if(left && root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        return recursive(root->left, true) + recursive(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return recursive(root,false);
    }
};