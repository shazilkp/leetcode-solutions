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
    int height(TreeNode * root, int & h){
        if(!root){
            h = 0;
            return 1;
        }
        int l; 
        if(!height(root->left,l)){
            return 0;
        }
        int r;
        if(!height(root->right,r)){
            return 0;
        }
        h = max(r,l) + 1
        ;
        if(abs(l -r) > 1){
           // cout << l << " " << r <<"\n";
            return 0;
        }
        else{
            return 1;
        }
    }
    bool isBalanced(TreeNode* root) {
        int h;
        return height(root,h);
    }
};
