class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        vector<int>dgtsm(nums.size(), 0);
        for(int i=0; i<nums.size(); i++)
        {
            int num = nums[i];
            if(num == 0)dgtsm[i] = num;
            else 
            {
            while(num >0)
            {
                dgtsm[i] = (dgtsm[i]) + (num%10);
                num = num/10;
            }
            }
            if(dgtsm[i] == i) return i;
        }
        return -1;
    }
};