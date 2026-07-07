class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> v;
        generatePathSum(root, sum, 0, v, result);
        return result;
    }

    void generatePathSum(TreeNode *root, int sum, int s, vector<int> v, vector<vector<int> >& result) {
        if (root==NULL) return ;

        s += root->val;
        v.push_back(root->val);

        if ( root->left==NULL && root->right==NULL) {
            if (s == sum) result.push_back(v);
            return;
        }

        generatePathSum(root->left, sum, s, v, result);
        generatePathSum(root->right, sum, s, v, result);
    }
};