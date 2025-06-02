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
    static bool comp(TreeNode * a, TreeNode * b) {
        return a->val < b->val;
    }
     void inorder(TreeNode * root,vector <TreeNode *> &res){
        if(root){
            inorder(root->left,res);
            res.push_back(root);
            inorder(root->right,res);
        }
    }
    void recoverTree(TreeNode* root) {
        vector <TreeNode *> res;
        inorder(root,res);
        vector <TreeNode *> resCopy = res;
        sort(resCopy.begin(),resCopy.end(),comp);
        // for(int i = 0 ; i < res.size() ; i++){
        //     cout << res[i]->val <<" ";
        // }
        // cout <<"\n";

        // for(int i = 0 ; i < res.size() ; i++){
        //     cout << resCopy[i]->val <<" ";
        // }
        // cout <<"\n";

        vector<pair<int,int>> v;

        for(int i = 0 ; i < res.size() ; i++){
            if(resCopy[i] != res[i]){
                v.push_back({i,res[i]->val});
            }
        }

        // for(auto t : v){
        //     auto [i ,val] = t;
        //     cout << i <<" " << val <<"\n";
        // }


        if(v.size() == 2){
            res[(v[0].first)]->val = v[1].second;
            res[(v[1].first)]->val = v[0].second;
        }
        /*
        if(index != -1){
            for(int i = 0 ; i < res.size() ; i++){
                if(val > (res[i])->val){
                    continue;
                }
                else{
                
                    res[index]->val = res[i]->val;
                    res[i]->val = val;
                    break;
                }
            }
        }
        */
    }
};
