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
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 0});
        int maxwidth = 0;
        while (!q.empty())
        {
            int size = q.size();
            int start = q.front().second;
            int end = q.back().second;
            maxwidth = max(maxwidth, end - start + 1);
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front().first;
                unsigned long long index = q.front().second;
                q.pop();
                if (node->left != NULL)
                {
                    q.push({node->left, 2 * index + 1});
                }
                if (node->right != NULL)
                {
                    q.push({node->right, 2 * index + 2});
                }
            }
        }
        return maxwidth;
    }
};