class Solution {
public:
    int maxProduct(int n) {
        int maxi1 =-1, maxi2=-1;
        vector<int>s;
        while(n>0)
        {
            int a = n%10;
            if(a>=maxi1) 
            {
                maxi2 = maxi1;
                maxi1 = a;
            }
            else if(a<maxi1 && a>maxi2) maxi2 = a;

            n /= 10;
        }
        return maxi1 * maxi2;
    }
};