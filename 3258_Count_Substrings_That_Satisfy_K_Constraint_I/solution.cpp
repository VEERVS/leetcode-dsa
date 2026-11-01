class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int left = 0, ans = 0, oneCount = 0, zeroCount = 0;
        for(int right=0; right<s.size(); right++){
            if(s[right] == '1'){
                oneCount++;
            }else{
                zeroCount++;
            }
            while(oneCount > k && zeroCount > k){
                if(s[left] == '1'){
                    oneCount--;
                }else{
                    zeroCount--;
                }
                left++;
            }
            ans += right-left+1;
        }
        return ans;
    }
};