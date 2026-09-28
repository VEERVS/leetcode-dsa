class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int diff = start ^ goal;

        while(diff!=0){
            diff = diff & (diff - 1);
            count ++;
        }
        return count;
    }
};