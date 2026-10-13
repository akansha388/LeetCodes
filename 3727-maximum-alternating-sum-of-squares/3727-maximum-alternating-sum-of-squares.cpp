class Solution {
public:
static bool CustomSort(int a, int b)
{
    return abs(a) < abs(b);
}

    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>score(nums.size());
        sort(nums.begin(), nums.end(), CustomSort);
        int n= nums.size();
        int i=0, epos=0, opos=1, j=n-1;
        while(i<=j)
        {
            if(epos<n)
            {
                score[epos] = nums[j];
                epos+=2;
                j--;
            }
            if(i<=j && opos<n)
            {
                score[opos] = nums[i];
                opos += 2;
                i++;
            }
        }
        long long maxscore=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(i%2 == 0)maxscore += (1LL * score[i]*score[i]);
            else maxscore -= (1LL * score[i]* score[i]);
        }
        return maxscore;
    }
};