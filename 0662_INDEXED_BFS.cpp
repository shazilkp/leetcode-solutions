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
    int widthOfBinaryTree(TreeNode* root) {
        queue <pair<TreeNode *,long long int>> q;
        q.push({root,0});
        int res = INT_MIN;
        while(!q.empty()){
            int size = q.size();
            long long first = q.front().second;
            long long last ;
            for(int i = 0 ; i < size; i++){
                auto curr = q.front(); q.pop();
                if((curr.first)->left){
                    q.push({(curr.first)->left,2*(curr.second - first)});
                }
                if((curr.first)->right){
                    q.push({(curr.first)->right,2*(curr.second - first) + 1});
                }
                last = curr.second - first;
            }
            res = max((long long)res,last+1);
        }
        return res;
    }
};
