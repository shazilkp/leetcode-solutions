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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector <TreeNode *> p_back;
        vector <TreeNode *> q_back;
        TreeNode * t = root;
        while(1){
            p_back.push_back(t);
            if(t == p){
                break;
            }
            if(t->val > p->val){
                t = t->left;
            }
            else if(t->val < p->val){
                t = t->right;
            }
        }
        t = root;
        while(1){
            q_back.push_back(t);
            if(t == q){
                break;
            }
            if(t->val > q->val){
                t = t->left;
            }
            else if(t->val < q->val){
                t = t->right;
            }
        }
        int i = 0;
        while(i < q_back.size() && i < p_back.size() && q_back[i] == p_back[i]){
            i++;
        }
        
        return q_back[i-1];
    }
};
