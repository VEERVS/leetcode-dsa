class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0, squareSum = 0, temp = n;
        while(temp!=0){
            digitSum += temp%10;
            squareSum += (temp%10) * (temp%10);
            temp /= 10;
        }
        return squareSum - digitSum >= 50;
    }
};