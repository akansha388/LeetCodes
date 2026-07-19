class Solution {
public:
    string smallestSubsequence(string s) {
    //     unordered_map<char,int>freqchar;
    //     for(int i=0; i<s.size(); i++) freqchar[s[i]]++;
    //     string t;
    //     for(auto &[c,ch] : freqchar)
    //     t.push_back(c);
    //     sort(t.begin(), t.end());
    //     return t;
    vector<int> last(26);
        for (int i = 0; i < s.size(); i++) 
        {
            last[s[i] - 'a'] = i;
        }
        vector<bool> use(26, false);
        string t;
        for (int i = 0; i < s.size(); i++) 
        {
            char c = s[i];
            if (use[c - 'a'])
                continue;
            while (!t.empty() && t.back() > c && last[t.back() - 'a'] > i) 
            {
                use[t.back() - 'a'] = false;
                t.pop_back();
            }
            t.push_back(c);
            use[c - 'a'] = true;
        }
        return t;
    }
};