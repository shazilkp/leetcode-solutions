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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        list<TreeNode * >q;
        q.push_back(root);
        int order = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int>tem;
            for(int i = 0 ; i < size ; i++){
                if(!order){
                    TreeNode * curr = q.front();q.pop_front();
                    tem.push_back(curr->val);
                    if(curr->left){
                        q.push_back(curr->left);
                    }
                    if(curr->right){
                        q.push_back(curr->right);
                    }
                }
                else{
                    TreeNode * curr = q.back();q.pop_back();
                    tem.push_back(curr->val);
                    if(curr->right){
                        q.push_front(curr->right);
                    }
                    if(curr->left){
                        q.push_front(curr->left);
                    }
                }
            }
            order = !order;
            res.push_back(tem);
        }

        return res;
    }
};
