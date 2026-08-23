class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int diff = 0;
        int q = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                q++;
            else
                diff += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                q--;
            else
                diff -= num[i] - '0';
        }

        if (q % 2 != 0)
            return true;

        return diff != -9 * (q / 2);
    }
};