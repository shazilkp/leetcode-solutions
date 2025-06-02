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
class BSTIterator {
public:
    vector<TreeNode * > inorder;
    int curr;

    void tra(TreeNode * root){
        if(root){
            tra(root->left);
            inorder.push_back(root);
            tra(root->right);
        }
    }

    BSTIterator(TreeNode* root) {
        tra(root);
        curr = 0;
    }
    
    int next() {
        int t = (inorder[curr])->val;
        curr++;
        return t;
    }
    
    bool hasNext() {
        return (curr< inorder.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
