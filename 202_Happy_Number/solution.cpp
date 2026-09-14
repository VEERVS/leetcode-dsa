class Solution {
public:
    bool isHappy(int n) {
        if(n == 1 || n == 7){
            return true;
        }
        int sum = 0;
        while(n>0){
            sum += (n%10)*(n%10);
            n /= 10;
        }
        if(sum<10 && sum!=1 && sum!=7){
            return false;
        }else{
            return isHappy(sum);
        }
    }
};