class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>freq;
        for(int x : arr){
            freq[x]++;
        }
        unordered_set<int>set;
        for(auto x : freq){
            int occur = x.second;
            if(set.count(occur) == 1){
                return false;
            }
            set.insert(occur);
        }
        return true;
    }
};