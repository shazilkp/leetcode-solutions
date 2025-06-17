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
    bool isSymmetric(TreeNode* root) {
        list<TreeNode * >q;
        q.push_back(root);
        while(!q.empty()){
            int size = q.size();
            list<TreeNode * >t = q;
            t.reverse();
            for(int i = 0; i < size; i++){
                
            }
            for(int i = 0 ; i < size ; i++){
                TreeNode * curr = q.front();q.pop_front();
                TreeNode * copy = t.front();t.pop_front();

                if(!curr && !copy){
                    continue;
                }
                if(copy && curr){
                    if(copy->val != curr->val){
                        return false;
                    }
                    q.push_back(curr->left);
                    q.push_back(curr->right);
                }
                else{
                    return false;
                }
            }
        }
        return 1;
    }
};
