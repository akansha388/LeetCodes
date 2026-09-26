class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string>knbase;
        for(auto &x : knowledge)
        {
            knbase[x[0]] = x[1];
        }
        string resstring = "";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(')
            {
                int j= i+1;
                while(s[j] != ')')
                {
                    j++;
                }
                string key = s.substr(i+1, j-i-1);
                if(knbase.find(key) != knbase.end()) resstring += knbase[key];
                else 
                resstring += "?";
                i=j;
            }
            else 
            resstring += s[i];
        }
        return resstring;
    }
};