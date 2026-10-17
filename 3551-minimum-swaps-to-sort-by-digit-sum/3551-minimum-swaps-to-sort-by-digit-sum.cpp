class Solution {
public:
    int digitSum(int n) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> sorted;

        for (int i = 0; i < n; i++) {
            sorted.push_back({digitSum(nums[i]), nums[i]});
        }

        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        int swaps = 0;
        vector<bool> visit(n, false);

        for (int i = 0; i < n; i++) {
            if (visit[i] || pos[sorted[i].second] == i) {
                continue;
            }

            int j = i;
            int cycle = 0;

            while (!visit[j]) {
                visit[j] = true;

                int val = sorted[j].second;
                j = pos[val];

                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};