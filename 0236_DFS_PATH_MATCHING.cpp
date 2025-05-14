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
    unordered_set<int> visited;

    int dfs(TreeNode * root, TreeNode * p,vector <TreeNode *> &stack){
        stack.push_back(root);
        //cout << "at "<<root->val<<"\n";
        if(root == p){
            
           return 1;
        }
        visited.insert(root->val);

        if(root->left){
            if (visited.find(root->left->val) == visited.end()) {
                if(dfs(root->left,p,stack) == 1){
                    return 1;
                }
            }
        }

        if(root->right){
            if (visited.find(root->right->val) == visited.end()) {
                if(dfs(root->right,p,stack) == 1){
                    return 1;
                }
            }
        }
        stack.pop_back();
        return 0;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * x = p;
        TreeNode * y = q;
        
        vector <TreeNode *> stack1;
        vector <TreeNode *> stack2;
        visited.clear();
        dfs(root,p,stack1);
        visited.clear();
        dfs(root,q,stack2);


        //cout << stack1.size() << "size" << stack2.size() << "\n";

        
        int i = 0,j = 0;

        



        //cout << stack1[i] << " & " << stack2[j]<<"\n";
        while(i < stack1.size() && j < stack2.size() && stack1[i] == stack2[j]){
            //cout << stack1[i] << " & " << stack2[j]<<"\n";
            i++;
            j++;
        }

        return stack1[i-1];
        
    }
};
