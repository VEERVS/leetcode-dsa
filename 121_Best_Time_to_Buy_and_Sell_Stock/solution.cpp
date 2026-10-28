class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MAXprofit = 0, left = 0;
        for(int right = 0; right<prices.size(); right++){
            if(prices[left] > prices[right]){
                left = right;
            }

            MAXprofit = max(MAXprofit, prices[right] - prices[left]);
        }
        return MAXprofit;
    }
};