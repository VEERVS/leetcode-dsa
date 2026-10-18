class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int winSum = 0;
        for(int i=0; i<k; i++){
            winSum += arr[i];
        }
        double winAvg = (double)winSum/k;

        if(winAvg >= threshold){
            count++;
        }

        for(int i=0; i<arr.size()-k; i++){
            winSum = winSum - arr[i] + arr[i+k];
            winAvg = (double)winSum/k;
            if(winAvg >= threshold){
                count++;
            }
        }
        return count;
    }
};