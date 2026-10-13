class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int sum = 0;
        sort(cost.begin(), cost.end(), greater<int>());

        for(int i=0; i<cost.size(); i++){
            if(i%3 == 2){
                continue;
            }
            sum += cost[i];
        }
        return sum;
    }
};