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
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> qeue;
        vector<vector<int>> vi;
        if(!root) return vi;
        qeue.push_back(root);
        while(!qeue.empty()){
            int sz = qeue.size();
            vector<int> v;
            while(sz--){
                TreeNode* node = qeue.front();
                v.push_back(node->val);
                qeue.pop_front();
                if(node->left) qeue.push_back(node->left);
                if(node->right) qeue.push_back(node->right);
            }
            vi.push_back(v);
        }
        return vi;
    }
};