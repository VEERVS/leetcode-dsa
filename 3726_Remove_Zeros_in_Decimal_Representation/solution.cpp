class Solution {
public:
    long long removeZeros(long long n) {
        long long sum = 0, ans = 0, temp = n;
        while (temp > 0) {
            if (temp % 10 != 0) {
                sum = (sum * 10) + (temp % 10);
            }
            temp /= 10;
        }

        while (sum > 0) {
            ans = (ans * 10) + (sum % 10);
            sum /= 10;
        }
        return ans;
    }
};