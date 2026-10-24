class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pFreq(26, 0);
        vector<int> winFreq(26, 0);
        vector<int> ans;
        int k = p.size();

        if(k > s.size()) return ans;

        for(int i=0; i<k; i++){
            pFreq[p[i] - 'a']++;
            winFreq[s[i] - 'a']++;
        }
        if(pFreq == winFreq){
            ans.push_back(0);
        }

        for(int i=k; i<s.size(); i++){
            winFreq[s[i-k] - 'a']--;
            winFreq[s[i] - 'a']++;
            if(pFreq == winFreq){
                ans.push_back(i-k+1);
            }
        }
        return ans;
    }
};