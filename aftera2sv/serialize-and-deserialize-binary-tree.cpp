class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#,";
        return to_string(root->val)+","+ serialize(root->left) + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        if (data == "#,") return nullptr;
        stringstream s(data);
        return helper(s);
    }

    TreeNode* helper (stringstream & s) {
        string str;
        getline(s, str, ',');
        if (str == "#") return nullptr;
        TreeNode* root = new TreeNode (stoi(str));
        root->left = helper(s);
        root->right = helper(s);
        return root;
    }
};