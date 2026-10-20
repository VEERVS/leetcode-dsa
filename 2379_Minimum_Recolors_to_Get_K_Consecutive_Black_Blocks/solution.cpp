class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int wCount = 0;
        for(int i=0; i<k; i++){
            if(blocks[i] == 'W'){
                wCount++;
            }
        }

        int minRecolors = wCount;

        for(int i=k; i<blocks.size(); i++){
            if(blocks[i] == 'W'){
                wCount++;
            }
            if(blocks[i-k] == 'W'){
                wCount--;
            }
            minRecolors = min(minRecolors, wCount);
        }
        return minRecolors;
    }
};