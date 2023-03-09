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
    unordered_map<int,int> mp;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        mp[root->val]++;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        int maxF = 0;
        int res = 0;
        for(auto v: mp){
            maxF = max(maxF, v.second);
        }
        vector<int> vt;
        for(auto v: mp){
            if(v.second == maxF) vt.push_back(v.first);
        }
        return vt;
    }
};