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
    int i = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(end < start) return NULL;
        auto node = new TreeNode(preorder[i++]);
        if(end == start) return node;
        int mid = lower_bound(inorder.begin(), inorder.end(), node->val) - inorder.begin();
        node->left = buildTree(preorder, inorder, start, mid - 1);
        node->right = buildTree(preorder,  inorder, mid + 1, end);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        copy(preorder.begin(), preorder.end(), back_inserter(inorder));
        sort(inorder.begin(), inorder.end());
        return buildTree(preorder, inorder, 0, inorder.size() - 1);
    }
};