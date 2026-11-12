class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        unordered_map<char, pair<int,int>>freq;
        for(int i=0; i<s.size(); i++)
        {
            if(freq.find(s[i]) == freq.end()) freq[s[i]] = {1,i};
            else freq[s[i]].first++;
        }
        for(int i=0; i<s.size(); i++)
        { 
            if(freq[s[i]].first == 1) return i;
        }
        return -1;
    }
};