class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()> s2.size()) return false;
        vector<int> s1Freq(26, 0);
        vector<int> winFreq(26, 0);
        int k = s1.size();

        for(int i=0; i<k; i++){
            s1Freq[s1[i] - 'a']++;
            winFreq[s2[i] - 'a']++;
        }

        if(s1Freq == winFreq){
            return true;
        }

        for(int i=k; i<s2.size(); i++){
            winFreq[s2[i-k] - 'a']--;
            winFreq[s2[i] - 'a']++;
            if(s1Freq == winFreq){
                return true;
            }
        }
        return false;
    }
};