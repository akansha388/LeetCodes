class Solution {
public:
    string smallestPalindrome(string s) {
        string t="",u="";
        int n = s.size();
        if(n % 2 == 0)
        {
            t = s.substr(0,(n/2));
            sort(t.begin(), t.end());
            u += t;
            reverse(t.begin(), t.end());
            u += t;
        }
        else if (n % 2 != 0)
        {
            t = s.substr(0,(n/2));
            sort(t.begin(), t.end());
            u += t;
            u += s[(n/2)];
            reverse(t.begin(), t.end());
            u += t;
        }
        return u;
    }
};