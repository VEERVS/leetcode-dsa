class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>freq;
        for(char x : magazine){
            freq[x]++;
        }
        for(char x : ransomNote){
            if(freq[x] == 0){
                return false;
            }
            freq[x]--;
        }
        return true;
    }
};