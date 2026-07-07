class Stack {
    public:
        
        void push(int x) {
            nums.push(x);
        }
        
        void pop() {
            if (!empty()) {
                int len = nums.size()-1;
                
                while ( len-->0) {
                    nums.push(nums.front());
                    nums.pop();
                }
                nums.pop();
            }
        }
        
        int top() {
            return nums.back();
        }
        
        bool empty() {
            return nums.empty();
        }

    private:
        queue<int> nums;
};