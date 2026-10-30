class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int countF=0, countT = 0, left = 0, ans = 0;

        for(int right=0; right<answerKey.size(); right++){
            if(answerKey[right] == 'T'){
                countT++;
            }else{
                countF++;
            }
            while((right-left+1) - max(countT, countF) > k){
                if(answerKey[left] == 'T'){
                    countT--;
                }else{
                    countF--;
                }
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};