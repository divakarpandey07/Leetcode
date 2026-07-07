class Solution {
public:
    map<TreeNode*, int> dict;
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        else if(dict.find(root) == dict.end())
        {
            int lwith = rob(root->left);
            int rwith = rob(root->right);
            int lwithout = 0, rwithout = 0;
            if(root->left != NULL)
                lwithout = rob(root->left->left) + rob(root->left->right);
            if(root->right != NULL)
                rwithout = rob(root->right->left) + rob(root->right->right);
            
            dict[root] = max(root->val + lwithout + rwithout, lwith + rwith);
        }
        return dict[root];
    }
};

class Solution {
public:
    int max(int a, int b) {
        return a > b ? a: b;
    }
    int max(int a, int b, int c) {
        return max(a, max(b,c));
    }
    int max(int a, int b, int c, int d) {
        return max(a, max(b, max(c,d)));
    }

    void rob_or_not(TreeNode* root, int& max_robbed, int& max_not_robbed) {
        
        if (root == NULL) {
            max_robbed = max_not_robbed = 0;
            return ;
        }

        
        int max_left_robbed, max_left_not_robbed;
        int max_right_robbed, max_right_not_robbed;
        rob_or_not(root->left, max_left_robbed, max_left_not_robbed);
        rob_or_not(root->right, max_right_robbed, max_right_not_robbed);

        
        max_robbed = root->val + max_left_not_robbed + max_right_not_robbed;

        
		
        max_not_robbed = max(max_left_robbed + max_right_robbed,
                             max_left_robbed + max_right_not_robbed,
                             max_left_not_robbed + max_right_robbed,
                             max_left_not_robbed + max_right_not_robbed);

    }
    int rob(TreeNode* root) {
        int robbed, not_robbed;
        rob_or_not(root, robbed, not_robbed);
        return max(robbed, not_robbed);
    }
};