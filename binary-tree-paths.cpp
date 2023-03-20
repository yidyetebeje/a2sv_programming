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
    set<string> vt;
    void buildString(TreeNode* root, string s, TreeNode* parent){
        if(root == NULL) {
            if(parent->left || parent->right) return;
            int size = s.size() - 2;
            string q = s.substr(0, size);
            vt.insert(q);
            return;
        }
        string p = s + to_string(root->val) + "->";
        buildString(root->left, p, root);
        buildString(root->right, p, root);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        buildString(root, "", root);   
        vector<string> p(vt.begin(), vt.end());
        return p;
    }
};