class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int winSum = 0, total = 0;
        for(int i=0; i<customers.size(); i++){
            if(grumpy[i] == 0){
                total += customers[i];
            }
        }

        for(int i=0; i<minutes; i++){
            if(grumpy[i] == 1){
                winSum += customers[i];
            }
        }

        int maxExtra = winSum;
        for(int right=minutes; right<grumpy.size(); right++){
            if(grumpy[right - minutes] == 1){
                winSum -= customers[right - minutes];
            }
            if(grumpy[right] == 1){
                winSum += customers[right];
            }
            maxExtra = max(maxExtra, winSum);
        }

        return total + maxExtra;
    }
};