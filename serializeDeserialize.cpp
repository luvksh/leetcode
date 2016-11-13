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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string s = "";
        while(!q.empty())
        {
            TreeNode* v = q.front();
            q.pop();
            if(v == NULL)
                s += ".";
            else
            {
                s += to_string(v->val);
                s += " ";
                q.push(v->left);
                q.push(v->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        queue<TreeNode*> q;
        TreeNode* root;
        if(data[i] == '.')
        {
            return NULL;
        }
        else
        {
            int j = data.find(" ", i);
            root = new TreeNode(stoi(data.substr(i, j-i)));
            i = j + 1;
            q.push(root);
        }
        TreeNode *t;
        TreeNode *u;
        while(i < data.size() && !q.empty())
        {
            t = q.front();
            q.pop();
            for(int loop = 0; loop < 2; loop++)
            {
                if(data[i] == '.')
                {
                    u = NULL;
                    i++;
                }
                else
                {
                    int j = data.find(" ", i);
                    u = new TreeNode(stoi(data.substr(i, j-i)));
                    i = j + 1;
                    q.push(u);
                }
                loop == 0 ? t->left = u : t->right = u;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));