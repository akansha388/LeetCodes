class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1=0, maxi2 = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>= maxi1)
            {
                maxi2=maxi1;
                maxi1=nums[i];
            }
            else if (nums[i]<maxi1 && nums[i]>maxi2)
            {
                maxi2= nums[i];
            }
        }
        return((maxi1-1) * (maxi2-1));
    }
};