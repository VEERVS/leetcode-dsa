class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;
        long long base = 1;
        while(n>0){
            int digit = n%10;

            if(digit!=0){
                ans.push_back(digit*base);
            }

            base *= 10;
            n /= 10;
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
};