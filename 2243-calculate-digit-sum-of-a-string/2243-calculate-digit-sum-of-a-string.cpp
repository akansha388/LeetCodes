class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) 
        {
            string temp = "";
            int i = 0;
            while (i < s.size()) 
            {
                int a = 0;
                int b = k;
                while (b-- && i < s.size()) 
                {
                    a += s[i] - '0';
                    i++;
                }
                temp += to_string(a);
            }
            s = temp;
        }
        return s;
    }
};