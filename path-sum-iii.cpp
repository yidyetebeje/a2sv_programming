class Solution {
public:
    int count = 0;
    void dfs(TreeNode* root, long long targetSum) {
        if (root == nullptr) return;
        targetSum -= root->val;
        if(targetSum == 0) count++; 
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
    }
    int pathSum(TreeNode* root, long long targetSum) {
        if(root == NULL) return 0;
        dfs(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return count;
    }
};