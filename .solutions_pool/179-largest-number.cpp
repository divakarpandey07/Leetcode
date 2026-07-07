class Solution {
    public:

        
        static bool comp (string& s1, string& s2) { return s1+s2 > s2+s1; }

        string largestNumber(vector<int> &num) {

            
            vector<string> v;
            for (int i=0; i<num.size(); i++) {
                v.push_back(to_string(num[i]));
            }

            
            sort(v.begin(), v.end(), comp);

            
            string result;
            for(int i=0; i<v.size(); i++ ){
                result+=v[i];
            }

            
            if (result[0]=='0') return "0";

            return result;
        }
};