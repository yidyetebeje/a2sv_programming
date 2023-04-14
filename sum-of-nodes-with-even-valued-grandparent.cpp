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
    int sum = 0;
    void traverse(TreeNode* root, TreeNode* parentNode, TreeNode* grandParent){
        if(root == NULL) return;
        if(grandParent && grandParent->val % 2 == 0) sum += root->val;
        traverse(root->left, root, parentNode);
        traverse(root->right, root, parentNode);
    }
    int sumEvenGrandparent(TreeNode* root) {
       auto left = root->left;
       auto right = root->right;
       traverse(left, root, NULL);
       traverse(right, root, NULL);
       return sum;
    }
};