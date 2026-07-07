const int LEVEL = 16; 

struct TrieNode { 
    TrieNode *child[2];  
    int cnt; 
    TrieNode() { 
        child[0] = child[1] = NULL; 
        cnt = 0; 
    } 
}; 
 
 

void insertTrie(TrieNode *root, int n) { 
    
    for (int i = LEVEL; i >= 0; i--) { 
        
        bool x = (n) & (1 << i); 
        
        if(!root->child[x]) { 
            
            root->child[x] = new TrieNode(); 
        } 
        
        root->child[x]->cnt += 1; 
        
        
        root = root->child[x]; 
    } 
} 

class Solution {
private:
    
    int countSmallerPairs(TrieNode * root,  int N, int K) { 
        
        int cntPairs = 0; 
        
        for (int i = LEVEL; i >= 0 && root; i--) {                 
            bool x = N & (1 << i); 
            bool y = K & (1 << i); 

            
            if (y == 0 ) { 
                
                
                root = root->child[x]; 
                continue;
            } 
            
            
            if(root->child[x]) {
                
                
                cntPairs  += root->child[x]->cnt; 
            }
            
            root = root->child[1 - x]; 
        } 
        return cntPairs; 
    } 
public:
    int countPairs(vector<int>& nums, int low, int high) {
        
        TrieNode* root = new TrieNode();
        
        int cnt = 0;
        for (auto& num : nums) {
            cnt += countSmallerPairs(root, num, high + 1) - countSmallerPairs(root, num, low);
            insertTrie(root, num);
        }
        
        
        return cnt;
    }
};