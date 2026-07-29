class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       int res=0, val=0;
       for(int i=0; i<gain.size(); i++)
       {
        val = val + gain[i];
        res = max(res, val);
       } 
       return res;
    }
};