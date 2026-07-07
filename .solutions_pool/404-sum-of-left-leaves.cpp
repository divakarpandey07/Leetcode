class Solution {
public:

    
    void sumOfLeftLeaves_recursion_v1(TreeNode* root, int& result) {
        if (root == NULL ) {
            return;
        }
        
        if (root->left && root->left->left == NULL && root->left->right == NULL) {
            result += root->left->val;
        }
        sumOfLeftLeaves_recursion_v1(root->left, result);
        sumOfLeftLeaves_recursion_v1(root->right, result);
        
    }
    
    int sumOfLeftLeaves_recursion_v2(TreeNode* root) {
        if (root == NULL ) {
            return 0;
        }
        int result = 0;
        if (root->left && root->left->left == NULL && root->left->right == NULL) {
            result = root->left->val;
        }
        result += sumOfLeftLeaves_recursion_v2(root->left) + sumOfLeftLeaves_recursion_v2(root->right);
        return result;
    }    
    

    int sumOfLeftLeaves(TreeNode* root) {
        srand(time(NULL));
        if (rand()%2) {
            int result = 0;
            sumOfLeftLeaves_recursion_v1(root, result);
            return result;
        } else {
            return sumOfLeftLeaves_recursion_v2(root);
        }
        
    }
};