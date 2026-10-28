class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> freq;
        int left = 0, count = 0;

        for(int right=0; right<s.size(); right++){
            freq[s[right]]++;
            while(freq.size() == 3){
                count += s.size() - right;
                
                freq[s[left]]--;
                if(freq[s[left]] == 0){
                    freq.erase(s[left]);
                }
                left++;
            }
        }
        return count;
    }
};