class Solution {
public:
    bool checkDivisibility(int n) {
        int a = n;
        int sum=0, mul=1;
        while(a>0)
        {
            int x = a%10;
            sum += x;
            mul = mul * x;
            a /=10;
        }
        int finalsum = sum + mul;
        if(n%finalsum == 0) return true;
        return false;
    }
};