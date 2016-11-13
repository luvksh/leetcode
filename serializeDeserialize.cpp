/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void _serialize(TreeNode* root, string& s)
    {
        if(root == NULL)
            s += ".";
        else 
        {
            s += to_string(root->val);
            s += " ";
            _serialize(root->left, s);
            _serialize(root->right, s);
        }
    }

    TreeNode* _deserialize(string data, int& i) {
        if(data[i] == '.')
        {
            i++;
            return NULL;
        }
        else
        {
            int j = data.find(" ", i);
            string num = data.substr(i, j-i);
            TreeNode* t = new TreeNode(stoi(num));
            i = j+1;
            t->left = _deserialize(data, i);
            t->right = _deserialize(data, i);
            return t;
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        _serialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return _deserialize(data, i);
    }
};