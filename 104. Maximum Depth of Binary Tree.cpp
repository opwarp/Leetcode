// 104. Maximum Depth of Binary Tree.cpp
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
    // int findDepth(TreeNode* root, int depth){
    //     if(root==NULL) return depth;
    //     depth++;
    //     return max(findDepth(root->left, depth), findDepth(root->right, depth));
    // }
    // int maxDepth(TreeNode* root) {
    //     return findDepth(root, 0);
    // }
    int maxDepth(TreeNode *root)
	{
	    return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
	}
};

