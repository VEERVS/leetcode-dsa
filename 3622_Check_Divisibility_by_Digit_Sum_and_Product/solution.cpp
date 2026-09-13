class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1, temp = n;
        while(temp!=0){
            sum += temp%10;
            prod *= temp%10;
            temp /= 10;
        }
        return n % (sum + prod) == 0;
    }
};