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
struct PairHash {
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U>& p) const {
        std::size_t h1 = std::hash<T>{}(p.first);
        std::size_t h2 = std::hash<U>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};
class Solution {
public:
    int dfs(TreeNode* root, bool break1,unordered_map<pair<TreeNode*, bool>,int, PairHash>& dp ){
        if(root == NULL) return 0;
        if(dp.count({root, break1})) return dp[{root, break1}];
        if(break1){
            dp[{root,break1}] = max(root->val + dfs(root->left, !break1,dp) + dfs(root->right, !break1,dp), dfs(root->left,true,dp) + dfs(root->right,true,dp)); 
        } 
        else dp[{root,break1}] = dfs(root->left, !break1,dp) + dfs(root->right, !break1,dp);
        return dp[{root,break1}];
    }
    int rob(TreeNode* root) {
        unordered_map<pair<TreeNode*, bool>,int, PairHash> dp;
        return max(dfs(root, true,dp), dfs(root, false,dp));
    }
};