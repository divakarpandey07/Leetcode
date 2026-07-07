class Solution_Time_Limit_Exceeded {
public:
    
    
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emails_chains; 
        unordered_map<string, string> names; 

        
        for(int i = 0 ; i<accounts.size();i++) {
            auto& account = accounts[i];
            auto& name = account[0];
            for (int j=1; j<account.size(); j++) {
                auto& email = account[j];
                if ( names.find(email) == names.end() ) {
                    emails_chains[email] = email;
                    names[email] = name;
                }
                join(emails_chains, account[1], email);
            }
        }

        
        unordered_map<string, set<string>> res;
        for( auto& acc : accounts ) {
            string e = find(emails_chains, acc[1]);
            res[e].insert(acc.begin()+1, acc.end());
        }

        
        vector<vector<string>> result;
        for (auto pair : res) {
            vector<string> emails(pair.second.begin(), pair.second.end());
            emails.insert(emails.begin(), names[pair.first]);
            result.push_back(emails);
        }
        return result;
    }

    string find(unordered_map<string, string>& emails_chains,
                string email) {
        while( email != emails_chains[email] ){
            email = emails_chains[email];
        }
        return email;
    }

    bool join(unordered_map<string, string>& emails_chains,
              string& email1, string& email2) {
        string e1 = find(emails_chains, email1);
        string e2 = find(emails_chains, email2);
        if ( e1 != e2 )  emails_chains[e1] = email2;
        return e1 == e2;
    }
};

class Solution {
public:
    
    
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emails_id; 
        unordered_map<int, int> emails_chains; 
        unordered_map<int, string> names; 

        
        for(int i = 0 ; i<accounts.size();i++) {

            
            
            emails_chains[i] = i;

            auto& account = accounts[i];
            auto& name = account[0];
            for (int j=1; j<account.size(); j++) {
                auto& email = account[j];
                if ( emails_id.find(email) == emails_id.end() ) {
                    emails_id[email] = i;
                    names[i] = name;
                }else {
                    join( emails_chains, i, emails_id[email] );
                }

            }
        }

        
        unordered_map<int, set<string>> res;
        for(int i=0; i<accounts.size(); i++) {
            int idx = find(emails_chains, i);
            res[idx].insert(accounts[i].begin()+1, accounts[i].end());
        }

        
        vector<vector<string>> result;
        for (auto pair : res) {
            vector<string> emails( pair.second.begin(), pair.second.end() );
            emails.insert(emails.begin(), names[pair.first]);
            result.push_back(emails);
        }
        return result;
    }

    int find(unordered_map<int, int>& emails_chains, int id) {
        while( id != emails_chains[id] ){
            id = emails_chains[id];
        }
        return id;
    }

    bool join(unordered_map<int, int>& emails_chains, int id1, int id2) {
        int e1 = find(emails_chains, id1);
        int e2 = find(emails_chains, id2);
        if ( e1 != e2 )  emails_chains[e1] = e2;
        return e1 == e2;
    }
};