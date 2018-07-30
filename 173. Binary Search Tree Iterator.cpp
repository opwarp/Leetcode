// 173. Binary Search Tree Iterator.cpp

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    int n = 0;
    vector <int> nodeStack; 
    BSTIterator(TreeNode *root) {
       stackTree(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return(n < nodeStack.size());
    }

    /** @return the next smallest number */
    int next() {
        
        if(hasNext()){   
            return nodeStack[n++]; 
        }else{
            return 0;
        } 
    }
private:
    void stackTree(TreeNode *root) {
        
        if(root!=NULL){
            if(root->left){
                stackTree(root->left);
            }
            nodeStack.push_back(root->val);
            if(root->right){
                stackTree(root->right);
            }
        }
    }
    
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */