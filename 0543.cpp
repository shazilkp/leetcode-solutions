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

    int max(int a,int b){
        return a > b ? a : b;
    }
    int height(TreeNode * root,int &diameter){
        if(!root){
            return 0;
        }
        int l =height(root->left,diameter);
        int r = height(root->right,diameter);
        diameter = max(diameter,l+r);
        return 1 + (max(l,r));
    }
    
    int diameterOfBinaryTree(TreeNode* root){
        int d = 0;
        int h = height(root,d);
        return d;
    }
};
