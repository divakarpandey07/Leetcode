class Solution {
public:
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    int lengthLongestPath(string input) {
        
         stringstream ss(input); 
         string line;
         int result = 0;
         
         vector<int> length;
         length.push_back(0); 
        
         while (getline(ss, line, '\n')) {
             
             int level = 0;
             while ( line[level++] == '\t'); 
             int len = line.size() - level + 1;

             
             if (line.find('.') != string::npos) { 
                 if ( length[level-1] + len > result ) {
                    result = length[level-1] + len;
                 }
             } else {
                
                 if (length.size() <= level) {
                     length.push_back(0); 
                 }
                 
                 
                 length[level] = length[level-1] + len + 1; 
             }
             
         }
         return result;
    }
};