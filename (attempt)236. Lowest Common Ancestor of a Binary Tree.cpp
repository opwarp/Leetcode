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
    
    bool found = false;
    TreeNode* lca = NULL;
    
    int findLCA(TreeNode* root, int a, int b){
        if(root==NULL){return 0;}
        int res1 = 0;
        if(root->val == a || root->val == b){
            res1 = 1;
        }
        int res2 = findLCA(root->left, a, b);
        if(!found&&res2 == 2){found = true; lca = root->left;}
        if (res1+res2==2){
            return 2;
        }
        int res3 = findLCA(root->right, a, b);
        if(!found&&res3 == 2){found = true; lca = root->right;}
        if  (res1+res2+res3==2){
            return 2;
        }
        return res1;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int res = findLCA(root, p->val, q->val);
        if(!found&&res == 2){found = true; lca = root;}
        return lca;
    }
};