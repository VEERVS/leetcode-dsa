class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = x ^ y;
        return __builtin_popcount(dist);
    }
};