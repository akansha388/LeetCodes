class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // string t;
        // int i=0, j=0;
        // while(i<word1.size() || j<word2.size())
        // {
        //     if(i<word1.size()) t+= word1[i];
        //     if(j<word2.size()) t+= word2[j];
        //     i++;
        //     j++;
        // }
        // return t;
        string t ="";
        int i=0;
        while(i<max(word1.size(), word2.size()))
        {
            if(i<word1.size()) t += word1[i];
            if(i<word2.size()) t += word2[i];
            i++;
        }
        return t;
    }
};