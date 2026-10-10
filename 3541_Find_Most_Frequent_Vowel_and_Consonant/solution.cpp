class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int>vowels;
        unordered_map<char, int>conso;

        for(char c : s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' ||c == 'u'){
                vowels[c]++;
            }
            else{
                conso[c]++;
            }
        }
        int max1 = 0;
        int max2 = 0;
        
        for(auto&c : vowels){
            max1 = max(max1, c.second);
        }
        
        for(auto&c : conso){
            max2 = max(max2, c.second);
        }

        return max1 + max2;
    }
};