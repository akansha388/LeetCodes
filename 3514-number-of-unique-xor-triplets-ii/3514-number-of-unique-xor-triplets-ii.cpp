
const int MAXX = 2048;
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // set<int>xor_n;
        // set<int>xor_2;
        // int i=0, j=0, k=0;
    //    while(i<=j && j<=k && k<nums.size())
    //    {
    //     int a = nums[i] ^ nums[j] ^ nums[k];
    //     xor_n.insert(a);
    //     if(k==j && k==i) k++;
    //     else if(k>j && k>i && j==i) j++;
    //     else if(k>j && j>i) i++;

    //    } 
    // for(int i=0; i<nums.size(); i++)
    // {
    //     for(int j=i; j<nums.size(); j++)
    //     {
    //         xor_n.insert(nums[i] ^ nums[j]);
    //     }
    // }
    // for(auto a: xor_n)
    // {
    //     for(int k=0; k<nums.size();k++)
    //     {
    //         xor_2.insert(a ^ nums[k]);
    //     }
    // }
    //    return xor_2.size();
        vector<bool> pairXor(MAXX, false);
        vector<bool> tripletXor(MAXX, false);
        int n = nums.size();
        for (int i = 0; i < n; i++) 
        {
            for (int j = i; j < n; j++) 
            {
                pairXor[nums[i] ^ nums[j]] = true;
            }
        }
        for (int x = 0; x < MAXX; x++) 
        {
            if (!pairXor[x]) continue;
            for (int k = 0; k < n; k++) 
            {
                tripletXor[x ^ nums[k]] = true;
            }
        }
        int ans = 0;
        for (bool x : tripletXor)
            ans += x;
        return ans;
    }
};