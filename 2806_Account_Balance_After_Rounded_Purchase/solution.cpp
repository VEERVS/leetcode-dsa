class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int roundOff = ((purchaseAmount + 5)/10)*10;
        return 100 - roundOff;
    }
};