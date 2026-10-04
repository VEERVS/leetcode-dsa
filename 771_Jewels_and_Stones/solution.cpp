class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        unordered_map<char, int>freq;
        for(char c : jewels){
            freq[c]++;
        }
        for(char c : stones){
            if(freq[c] > 0){
                count++;
            }
        }
        return count;
    }
};