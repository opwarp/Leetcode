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
    TreeNode* findLCA(int a, int b, TreeNode* root){
        if(root == NULL){return NULL;}
        //
        if(root->val < a){return findLCA(a, b, root->right);} // val<a<b, a, b on right
        if(root->val > b){return findLCA(a, b, root->left);} // a<b<val, a,b on left
        return root; //a<=val<=b, return root
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a,b;
        if(p->val > q->val){a=q->val; b=p->val;}
        else{a=p->val; b=q->val;}
        return findLCA(a, b, root);
    }
};