// 129. Sum Root to Leaf Numbers.cpp
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
    vector <int> nums;
    void getNum(TreeNode* root, int num){
        // cout<<num<<endl;
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            nums.push_back(num*10+root->val);
            return;
        }
        getNum(root->left, num*10+root->val);
        getNum(root->right, num*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        getNum(root, 0);
        int sum=0;
        for(auto& i:nums){
            sum+=i;
        }
        return sum;
    }
};