class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    int dfs(TreeNode* root, int& result) {
        if (root == NULL) return 0;

        int left_move = dfs(root->left, result);
        int right_move = dfs(root->right, result);
        result += (abs(left_move) + abs(right_move));

        
        
        return root->val + left_move + right_move - 1;
    }
};