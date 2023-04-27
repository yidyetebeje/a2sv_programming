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
    vector<double> averageOfLevels(TreeNode* root) {
        deque<TreeNode*> qeue;
        vector<double> vi;
        if(!root) return vi;
        qeue.push_back(root);
        while(!qeue.empty()){
            int sz = qeue.size();
            vector<int> v;
            double sum = 0;
            long long n = 0;
            while(sz--){
                TreeNode* node = qeue.front();
                sum += node->val;
                n++;
                qeue.pop_front();
                if(node->left) qeue.push_back(node->left);
                if(node->right) qeue.push_back(node->right);
            }
            vi.push_back(sum/n);
        }
        return vi;
    }
};