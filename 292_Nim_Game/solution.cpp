class Solution {
public:
    bool canWinNim(int n) {
        return n==1 || n==2 || n%4!=0;
    }
};