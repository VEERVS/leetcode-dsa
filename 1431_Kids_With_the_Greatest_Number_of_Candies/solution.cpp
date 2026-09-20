class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int max = *max_element(candies.begin(), candies.end());
        for(int i=0; i<candies.size(); i++){
            ans.push_back(candies[i] + extraCandies >= max);
        }
        return ans;
    }
};