class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = accumulate(word1.begin(), word1.end(), string(""));
        string b = accumulate(word2.begin(), word2.end(), string(""));
        return a == b;
    }
};