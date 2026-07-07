class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    
    int next();
    
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
private:
    bool m_hasNext;
    int m_next;
    
    void takeNext() {
        m_hasNext = Iterator::hasNext();
        if (m_hasNext) {
            m_next = Iterator::next();
        }  
    }
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        
        
        
        takeNext();
    }

    
    int peek() {
        return m_next;
    }

    
    
    int next() {
        int temp = m_next;
        takeNext();
        return temp;
        
    }

    bool hasNext() const {
        return m_hasNext;
    }
};