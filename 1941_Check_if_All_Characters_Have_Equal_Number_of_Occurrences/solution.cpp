class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> freq;
        for(char x : s){
            freq[x]++;
        }

        int val = freq[s[0]];

        for(auto&pair : freq){
            if(pair.second != val){
                return false;
            }
        }
        return true;
    }
};