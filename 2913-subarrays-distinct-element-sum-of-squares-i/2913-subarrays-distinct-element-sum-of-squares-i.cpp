class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int l = 0; l < n; l++) 
        {
            vector<int> freq(101, 0);
            int distinct = 0;
            for (int r = l; r < n; r++) 
            {
                if (freq[nums[r]] == 0) 
                    distinct++;
                freq[nums[r]]++;
                res += distinct * distinct;
            }
        }
        return res;
    }
};