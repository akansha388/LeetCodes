class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;

        // Store 1, 2, ..., n
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        // factorial
        int fact = 1;
        for (int i = 1; i < n; i++) {
            fact *= i;
        }

        // Convert k to 0-based
        k--;

        string ans = "";

        for (int i = n; i >= 1; i--) {
            int index = k / fact;

            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);

            k = k % fact;

            if (i > 1) {
                fact /= (i - 1);
            }
        }

        return ans;
    }
};