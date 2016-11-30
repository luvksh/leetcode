/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* mis1 = NULL;
        TreeNode* mis2 = NULL;
        InOrder(root, mis1);
        RevOrder(root, mis2);
        int temp = mis1->val;
        mis1->val = mis2->val;
        mis2->val = temp;
    }
    
    bool InOrder(TreeNode* root, TreeNode*& temp)
    {
        if(root == NULL) 
        {
            return false;
        }
        if(InOrder(root->left, temp))
            return true;
        if(temp != NULL)
        {
            if(temp->val > root->val)
                return true;
        }
        temp = root;
        if(InOrder(root->right, temp))
        {
            return true;
        }
        return false;
    }
    bool RevOrder(TreeNode* root, TreeNode*& temp)
    {
        if(root == NULL) 
        {
            return false;
        }
        if(RevOrder(root->right, temp))
            return true;
        if(temp != NULL)
        {
            if(temp->val < root->val)
                return true;
        }
        temp = root;
        if(RevOrder(root->left, temp))
        {
            return true;
        }
        return false;
    }
};