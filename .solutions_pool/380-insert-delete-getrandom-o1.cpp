class RandomizedSet {
public:
    
    RandomizedSet() {
        srand(time(NULL));
    }
    
    
    bool insert(int val) {
        if ( find(val) ) return false; 
        data.push_back(val);
        valpos[val] = data.size() - 1;
        return true;
    }
    
    
    bool remove(int val) {
        if ( !find(val) ) return false; 
        
		
        int _idx = valpos[val];
        int _val = data.back();
        
        data[_idx] = _val;
        valpos[_val] = _idx;
        
        valpos.erase(val);
        data.pop_back();
        return true;
    }
    
    
    int getRandom() {
        return data[ rand() % data.size() ];
    }
    
private:    
    unordered_map<int, int> valpos; 
    vector<int> data;
    bool find(int val) {
        return (valpos.find(val) != valpos.end());
    }
    
};