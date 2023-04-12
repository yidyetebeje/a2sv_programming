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
    void dfs(TreeNode* root, string s){
        if(root == nullptr){
             return;
        }
        s =  s + to_string(root->val);
        if(root->left == nullptr && root->right == nullptr){
            sum += stoi(s);
        }
        dfs(root->left,s);
        dfs(root->right,s);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, "");
        return sum;
    }
};