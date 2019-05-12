// 257. Binary Tree Paths.cpp
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
    vector<string> paths;
    void getPath(TreeNode* root, string path){
        if(root == NULL) return;
        if(root->right == NULL && root->left == NULL) {
            path = path + to_string(root->val);
            paths.push_back(path);
            return;
        }
        path = path + to_string(root->val) + "->";
        getPath(root->left, path);
        getPath(root->right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        getPath(root, path);
        return paths;
    }
};