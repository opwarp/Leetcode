// 114. Flatten Binary Tree to Linked List.cpp

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
    TreeNode* recurFlatten(TreeNode* root){
        if(root == NULL) return NULL;
        if(root->left == NULL && root->right ==NULL) return root;
        if(root->left == NULL && root->right != NULL) return recurFlatten(root->right);
        if(root->left != NULL && root->right == NULL){
            root->right = root->left;
            root->left = NULL;
            return recurFlatten(root->right);
        } 
        TreeNode* endL = recurFlatten(root->left); //get left endpoint
        TreeNode* endR = recurFlatten(root->right);//get right endpoint
        //concat flatened right and left
        endL->right = root->right;
        root->right = root->left;
        root->left = NULL;
        return endR; //pass end point
    }
    void flatten(TreeNode* root) {
        recurFlatten(root);
    }
};