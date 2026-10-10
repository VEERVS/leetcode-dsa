class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> freq;

        for(char c : s){
            freq[c]++;
            if(freq[c] == 2){
                return c;
            }
        }
        return 0;
    }
};