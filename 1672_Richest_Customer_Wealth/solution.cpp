#include<algorithm>

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for(auto customer : accounts){
            int sum = accumulate(customer.begin(), customer.end(), 0);
            maxWealth = max(maxWealth, sum);
        }
        return maxWealth;
    }
};