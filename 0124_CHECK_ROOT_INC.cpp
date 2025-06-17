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
    int traverse(TreeNode* root, int & sum){
        if(!root){
            return 0;
        }

        int l = max(0,traverse(root->left,sum));
        int r = max(0,traverse(root->right,sum));
        int tsum = l +r + root->val;
        sum = max(tsum,sum);
        return max(l,r) + root->val; 
   
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        traverse(root,sum);
        return sum;
    }
};
