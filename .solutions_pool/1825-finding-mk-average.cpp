class MKAverage {
private:
    vector<int> ringBuf;
    int pos;
    multiset<int> left, mid, right;
    long sum;
    long maxmin;
    int m;
    int k;
private:
    template <class T>
    void print(T& v) {
        for(auto it : v){
            cout << it << "+";
        }
        cout <<endl;
    }
    int takeMax(multiset<int>& s) {
        auto it = --s.end();
        int n = *it;
        s.erase(it);
        return n;
    }
    int takeMin(multiset<int>& s) {
        auto it = s.begin();
        int n = *it;
        s.erase(it);
        return n;
    }
public:
    MKAverage(int _m, int _k): ring(_m, 0), m(_m), k(_k), sum(0), pos(0), maxmin(0) {
        
    }
    
    void ins(int n) {
        left.insert(n);
        maxmin += n;
        if (left.size() > k ) {
            int n = takeMax(left);
            right.insert(n);
            if (right.size() > k) {
                int n = takeMin(right);
                maxmin -= n;
                mid.insert(n);
            }
        }
    }
    
    void del(int n) {
        if (n <= *(left.rbegin())) {
            left.erase(left.find(n));
            int n1 = takeMin(mid);
            left.insert(n1);
            maxmin += (n1 - n);
        }else if (n >= *(right.begin())) {
            right.erase(right.find(n));
            int n1 = takeMax(mid);
            right.insert(n1);
            maxmin += (n1 - n);
        }else {
            mid.erase(mid.find(n));
        }   
    }
    
    void addElement(int num) {
        pos++; 
        if (pos > m) {
            int n = ringBuf[pos % m];
            sum -= n;
            del(n);
            
            
        } 
        
        ringBuf[pos % m] = num ;
        sum += num;
        
        ins(num);
        
        
    }

    
    int calculateMKAverage() {
        if (pos < m) return -1;
        
        return (sum - maxmin) / (m-2*k);
    }
};

class MKAverage1 {
private:
    vector<int> ring;
    int pos;
    vector<int> sort;
    long sum;
    long maxmin;
    int m;
    int k;
private:
    template <class T>
    void print(T& v) {
        for(auto it : v){
            cout << it << "+";
        }
        cout <<endl;
    }
public:
    MKAverage1(int _m, int _k):  ring(_m,0), m(_m), k(_k), sum(0), pos(0), maxmin(0) {
        
    }
    void ins(int n) {
        
        int low = 0, high = sort.size()-1;
        int mid;
        if (high < 0 || n >= sort[high]) {
            sort.push_back(n); 
            return;
        }
        
        while(low <= high){
            mid = low + (high-low)/2;
            if (sort[mid]  <= n ) low = mid + 1;
            else high = mid - 1;
        }
        auto it = sort.begin() + low;
        sort.insert(it, n);
    }
    
    void del(int n) {
        int len = sort.size();
        int low = 0, high = len -1;
        int mid;
        while(low <= high){
            mid = low + (high-low)/2;
            if (sort[mid] == n) break;
            if (sort[mid]  < n ) low = mid + 1;
            else high = mid - 1;
        }
        
        if (low > high) return;
        
        auto it = sort.begin() + mid;
        sort.erase(it);
        
    }
    void addElement(int num) {
        pos++;
        
        if (pos > m) {
            int n = ring[pos % m];
            sum -= n;
            
            int len = sort.size();
            if (n <= sort[k-1] ) maxmin += (sort[k]-n);
            else if (n >= sort[len-k]) maxmin += (sort[len-k-1] - n);
            
            del(n);
            
            
        } 
        
        
        ring[pos % m] = num;
        sum += num;
        
        if (sort.size() < 2*k ) {
            maxmin += num;
        } else {
            int len = sort.size();
            if (num <= sort[k-1]) maxmin += (num - sort[k-1]);
            else if (num >= sort[len-k]) maxmin += (num -sort[len-k]);
        }
        
        ins(num);
        
        
    }

    
    int calculateMKAverage() {
        if ( pos < m) return -1;
        
        return (sum - maxmin) / (m-2*k);
    }
};