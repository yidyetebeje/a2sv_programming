/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int dfs(Node* root){
        if(!root) return 0;
        auto childrens = root->children;
        int d = 0;
        for(auto v: childrens){
            d = max(d, dfs(v) + 1);
        }
        return d;
    }
    int maxDepth(Node* root) {
        if(!root) return 0;
        return dfs(root) + 1;
    }
};