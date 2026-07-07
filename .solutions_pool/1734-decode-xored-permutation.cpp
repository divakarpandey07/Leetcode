class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        
        
        
        
        
        
        
        
        
        int nxor = (encoded.size() / 2 + 1) % 2 ;
        
        
        
        
        
        
        
        
        int mxor = encoded[1];
        for (int i=3; i< encoded.size(); i+=2) {
            mxor ^= encoded[i];
        }
        
        
        x = nxor ^ mxor;
        
        vector<int> result;
        result.push_back(x);
        
        
        
        for (int i=0; i< encoded.size(); i++) {
            x = x ^ encoded[i];
            result.push_back(x);
        }
        
        return result;
    }
};