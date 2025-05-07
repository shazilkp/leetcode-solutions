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
    void printRight(TreeNode* root) {
        while (root) {
            std::cout << root->val << " ";
            root = root->right;
        }
        std::cout << std::endl;
    }


    TreeNode * tra(TreeNode * root){
        if(root){
            TreeNode * head = root;
            TreeNode * left = root->left;
            TreeNode * right = root->right;
            root->left = NULL;
            root->right = tra(left);
            TreeNode* temp = head;
            while (temp->right) {
                temp = temp->right;
            }
            temp->right = tra(right);
            return head;
        }
        return NULL;
    }
    void flatten(TreeNode* root) {
        TreeNode * ll = tra(root);
    }
};
