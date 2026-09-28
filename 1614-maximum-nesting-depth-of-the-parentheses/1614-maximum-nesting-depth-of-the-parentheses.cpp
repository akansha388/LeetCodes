class Solution {
public:
    int maxDepth(string s) {
        int cnt =0;
        stack<int>st;
        int a=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(') 
            {
                st.push(s[i]);
                a++;
            }
            else if(s[i] == ')')
            {
                cnt = max(cnt, a);
                st.pop();
                a--;
            }
        }
        return cnt;    
    }
};