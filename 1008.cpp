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
    TreeNode* helper(vector<int>& preorder,int curr,int j){
        TreeNode * root = NULL;
        if(curr == j){
           root = new TreeNode(preorder[curr]);
           return root; 
        }
        if(curr < j){
            TreeNode * root = new TreeNode(preorder[curr]);
            int nextj= -1;
            for(int i = curr + 1 ; i <= j; i++){
                if(preorder[i] > root->val){
                    nextj = i;
                    break;
                }
            }
            root->left = helper(preorder,curr+1,nextj == -1 ? j : nextj-1);
            if(nextj != -1){
                root->right = helper(preorder,nextj,j);
            }
            return root;
        }
        return NULL;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder,0,preorder.size()-1);
    }
};
