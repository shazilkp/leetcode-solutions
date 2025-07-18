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
    bool traverse(TreeNode * p, TreeNode * q){
        if(!p && !q){
            return true;
        }
        if(p && q){
            if(p->val == q->val){
                if(!traverse(p->left,q->left)){
                    return false;
                }
                if(!traverse(p->right,q->right)){
                    return false;
                }
                return true;
            }
            else{
                return false;
            }
            
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traverse(p,q);
    }
};
