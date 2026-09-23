class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long sum = 0;
        for (int num : nums) 
        {
            sum += num;
        }
        long long target = sum - x;
        if (target < 0) 
        {
            return -1;
        }
        if (target == 0) 
        {
            return n;
        }
        int i = 0;
        long long curr = 0;
        int longest = -1;
        for (int j = 0; j < n; j++) 
        {
            curr += nums[j];
            while (curr > target && i <= j) 
            {
                curr -= nums[i];
                i++;
            }
            if (curr == target) 
            {
                longest = max(longest, j - i + 1);
            }
        }
        if (longest == -1) {
            return -1;
        }
        return n - longest;
    }
};