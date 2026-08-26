class Solution {
public:
    string s;
    string encode(vector<string>& strs) {
        int n = strs.size();
        s = "";
        for(int i = 0; i < n; i++){
            string t = strs[i];
            s += to_string(t.size()) + '#' + t;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        
        int i = 0;
        while(i < s.size()){
            int del = s.find('#', i);
            int len = stoi(s.substr(i, del-i));
            ans.push_back(s.substr(del+1, len));
            
            i = del+len+1;
        }

        return ans;
    }
};
