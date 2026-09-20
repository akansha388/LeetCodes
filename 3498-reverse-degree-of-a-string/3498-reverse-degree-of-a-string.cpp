class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int revAlpha = 26 - (s[i] - 'a'); 
            int pos = i + 1;                   
            sum += revAlpha * pos;
        }
        return sum;
    }
};