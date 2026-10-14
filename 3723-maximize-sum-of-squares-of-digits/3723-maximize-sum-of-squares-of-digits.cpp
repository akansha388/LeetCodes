class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num)
            return "";
        string res = "";
        while (num > 0) 
        {
            if (sum >= 9) 
            {
                res += '9';
                sum -= 9;
            }
            else 
            {
                res += char('0' + sum);
                sum = 0;
            }
            num--;
        }
        return res;
    }
};