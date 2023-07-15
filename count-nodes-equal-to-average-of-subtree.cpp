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
    int x = 0;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL)return {0,0};
        auto left = solve(root->left);
        auto right = solve(root->right);
        auto sum = left.first + right.first + root->val;
        auto count = left.second + right.second + 1;
        if(root->val == (sum / count)){
            x++;
        }
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        x = 0;
        solve(root);
        return x;
    }
};