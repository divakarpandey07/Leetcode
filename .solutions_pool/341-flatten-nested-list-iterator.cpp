class NestedIterator {
private:
    vector<int> v;
    int index;
    void flatten(vector<NestedInteger> &nestedList) {
        for (auto item : nestedList){
            if (item.isInteger()){
                v.push_back( item.getInteger() );
            }else{
                flatten( item.getList() );
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        index = 0;
    }

    int next() {
        return v[index++];
    }

    bool hasNext() {
        return (index < v.size() );
    }
};