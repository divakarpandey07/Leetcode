class Solution {
public:
    bool checkPowersOfThree(int n) {
        return checkPowersOfThree_Base3(n);
        return checkPowersOfThree_DFS(n, 1);
    }
    
    bool checkPowersOfThree_DFS(int n, int p) { 
        if (n == p ) return true;
        if (n < p ) return false;
        
        return (checkPowersOfThree_DFS(n-p, p*3) || checkPowersOfThree_DFS(n, p*3));
    }
    
    bool checkPowersOfThree_Base3(int n) { 
        for (; n>0; n/=3) {
            if (n%3 == 2) return false;
        }
        return true;
    }
};