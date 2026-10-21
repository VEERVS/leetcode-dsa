class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int winSize = n-k;
        int total = 0;
        for(int i=0; i<n; i++){
            total += cardPoints[i];
        }
        int winSum = 0;

        for(int i=0; i<winSize; i++){
            winSum += cardPoints[i];
        }

        int minSum = winSum;

        for(int i=winSize; i<n; i++){
            winSum = winSum + cardPoints[i] - cardPoints[i-winSize];
            minSum = min(minSum, winSum);
        }

        return total - minSum;
    }
};