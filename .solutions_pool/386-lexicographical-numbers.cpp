class Solution {
    

public:
    vector<int> lexicalOrder01(int n) {
        vector<int> result;
        for (int i=1; i<=n; i++) {
            result.push_back(i);
        }
        sort(result.begin(), result.end(), this->myComp);
        return result;
    }
private:
    static bool myComp(int i,int j) { 
        static char si[32]={0}, sj[32]={0};
        sprintf(si, "%d\0", i);
        sprintf(sj, "%d\0", j);
        return (strcmp(si, sj)<0); 
    }
    
    

public:
    vector<int> lexicalOrder02(int n) {
        vector<int> result;
        for (int i=1; i<=n && i<=9; i++) {
            result.push_back(i);
            lexicalOrder_helper(i, n, result);
        }
        return result;
    }
    
private:
    void lexicalOrder_helper(int num, int& n, vector<int>& result) {
        for (int i=0; i<=9; i++) {
            int tmp = num * 10 + i;
            if (tmp > n) {
                break;
            }
            result.push_back(tmp);
            lexicalOrder_helper(tmp, n, result);
        }
    }

public :
    vector<int> lexicalOrder03(int n) {
        vector<int> result;
        int curr = 1;
        while (result.size()<n) {
            
            
            
            
            
            for (; curr <= n; curr*=10 ) {
                result.push_back(curr);
            }
            
            
            
            
            
            
            
            
            curr = curr/10 + 1;
            for (;  curr <= n &&  curr % 10 != 0; curr++) {
                result.push_back(curr);
            }

            
            
            
            
            
            
            
            for (; curr%10 == 0; curr/=10);
           
        }
        return result;
    }
    
    

public:
    vector<int> lexicalOrder(int n) {
        srand(time(NULL));
        if (rand()%2) 
            return lexicalOrder02(n); 
        else 
            return lexicalOrder03(n); 
    }

};