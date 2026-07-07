class RandomizedCollection {
public:
    
    RandomizedCollection() {
        srand(time(NULL));
    }
    
    
    bool insert(int val) {
        data.push_back(val);
        valpos[val].insert( data.size() - 1 );
        return (valpos[val].size() == 1);
    }
    
    
    bool remove(int val) {
        
        if (!find(val)) return false;
        
        
        
        int _idx = *(valpos[val].begin());
        int _val = data.back();
        
        valpos[_val].insert(_idx);
        data[_idx] = _val;
        
        valpos[val].erase(_idx);
        if (valpos[val].size()==0){
            valpos.erase(val);
        }
        
        data.pop_back();
        if ( _idx < data.size() ){
            valpos[_val].erase(data.size());
            valpos[_val].insert(_idx);
        }
        
        return true;        
    }
    
    
    int getRandom() {
        return data[ rand() % data.size() ];
    }
private:
    unordered_map<int, unordered_set<int>> valpos; 
    vector<int> data;
    bool find(int val) {
        return (valpos.find(val) != valpos.end());
    }
   
};