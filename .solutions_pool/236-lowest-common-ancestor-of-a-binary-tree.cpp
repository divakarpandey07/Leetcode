class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path) {
        if (root==NULL) return false;
        if (root == p) {
            path.push_back(p);
            return true;
        }
        
        path.push_back(root);
        if (findPath(root->left, p, path)) return true;
        if (findPath(root->right, p, path)) return true;
        path.pop_back();
        
        return false;
    }

    
    TreeNode* lowestCommonAncestor01(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> path1, path2;
        
        if (!findPath(root, p, path1)) return NULL;
        if (!findPath(root, q, path2)) return NULL;
        
        int len = path1.size() < path2.size() ? path1.size() : path2.size();
        TreeNode* result = root;
        for(int i=0; i<len; i++) {
            if (path1[i] != path2[i]) {
                return result;
            }
            result = path1[i];
        }
        return result;
    }
    
    
    TreeNode* lowestCommonAncestor02(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        
        if (root==NULL || root == p || root == q) return root;
        
        
        TreeNode* left = lowestCommonAncestor02(root->left, p, q);
        
        TreeNode* right = lowestCommonAncestor02(root->right, p, q);
        
        
        if (left==NULL) return right;
        
        if (right==NULL) return left;
        
        return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        srand(time(0));
        if (random()%2) {
            return lowestCommonAncestor02(root, p, q);
        }
        return lowestCommonAncestor01(root, p, q);
    }
};