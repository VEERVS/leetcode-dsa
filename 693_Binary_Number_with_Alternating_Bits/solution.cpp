class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n!=0){
            int last = n & 1;
            n = n >> 1;
            int next = n & 1;
            if(next^last==0){
                return false;
            }
        }
        return true;
    }
};