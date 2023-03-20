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
    map<int,vector<pair<int, int>>> mp;
    vector<int> sort(vector<pair<int,int>> v){
        std::sort(v.begin(), v.end() , [](auto a, auto b){
                if(a.second < b.second) return true;
                if(a.second == b.second){
                    return a.first < b.first;
                }
                return false;
            });
        vector<int> vi;
        for(auto x: v){
            vi.push_back(x.first);
        }
        return vi;
    }
    void inorder(TreeNode* root, int col, int row){
        if(root == NULL) return;
        mp[col].push_back(make_pair(root->val, row));
        inorder(root->left, col - 1, row + 1);
        inorder(root->right, col + 1, row + 1);
       
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        inorder(root, 0, 0);
        vector<vector<int>> fi;
        for(auto v: mp){
            fi.push_back(sort(v.second));
            for(auto i: v.second){
                cout << i.first << " ";
            }
            cout << endl;
        }
        return fi;
    }
};