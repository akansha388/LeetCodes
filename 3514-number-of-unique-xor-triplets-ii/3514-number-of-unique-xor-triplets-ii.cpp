class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // Since 1500 fits in 11 bits, any XOR result also fits in 11 bits, a 11-bit number can have values from 0 to (2^11) - 1 = 2047, so we need a vector of size 2048, and making it false so that if in xor that number comes we can make it true and in last just calculate for those
        vector<bool>xor_1(2048, false);
        vector<bool>xor_2(2048, false);
        int cnt = 0;//counting unique pairs

        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i; j<nums.size(); j++)
            {
                xor_1[nums[i] ^ nums[j]] = true; // xor of 2 elements first 
            }
        }
        for(int i=0; i<2048; i++)
        {
            if(!xor_1[i]) continue;
            for(int j=0; j<nums.size(); j++)
            {
                xor_2[i ^ nums[j]] = true;//xor of all valid xors with every element of that array nums
            }
        }
        for(int i=0; i<2048; i++)
        {
            if(xor_2[i]) cnt++;//count number of distinct values 
        }
        return cnt;
    }
};