class Solution {
public:
    int findComplement(int num) {
        if(num==0) return 1;
        int original = num, mask = 0;

        while(num != 0){
            mask = mask << 1 | 1;
            num = num >> 1;
        }

        return (~original) & mask;
    }
};