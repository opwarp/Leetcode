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
    void keepNodes(vector<vector<int>> &level, TreeNode * node, int depth){
        if(node == NULL) return;
        while(level.size()<depth+1){//keep size equar to depth
            // cout<<level.size()<<endl;
            level.push_back(vector<int> ());
        }
        level[depth].push_back(node->val);
        // cout<<level[depth][0]<<endl;
        keepNodes(level, node->left, depth+1);
        keepNodes(level, node->right, depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level;
        // TreeNode * node;
        keepNodes(level, root, 0);
        return level;
    }
};