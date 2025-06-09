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
    int inorder(TreeNode* root,int k,vector <int>&res){
        if(root){
            if(inorder(root->left,k,res) == 0){
                return 0;
            }
            res.push_back(root->val);
            if(res.size() >= k){
                return 0;
            }
            if(inorder(root->right,k,res) == 0){
                return 0;
            }
        }
        return 1;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>res;
        inorder(root,k,res);
        return res[k-1];
    }
};
