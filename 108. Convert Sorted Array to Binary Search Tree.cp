// 108. Convert Sorted Array to Binary Search Tree.cpp
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
    
    TreeNode* buildBST(int size, vector<int>::iterator bgn, vector<int>::iterator end){
        if(bgn == end) return NULL;
        
        int lsize = size/2;
        auto it = bgn + lsize;
        int rsize = end-it-1;
        TreeNode* root = new TreeNode(*it);
        root->left = buildBST(lsize, bgn, it);
        root->right = buildBST( rsize, it+1, end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = buildBST(nums.size(), nums.begin(), nums.end());
        return root;
    }
};