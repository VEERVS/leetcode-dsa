int countGoodRotations(int* nums, int n) {
    int h = n / 2, ans = 0;
    long long total = 0, sum = 0;

    for (int i = 0; i < n; i++){
        total += nums[i];
    }
    
    int* peldarquin = nums;
    
    for (int i = 0; i < h; i++){
        sum += peldarquin[i];
    }

    for (int i = 0; i < n; i++) {
        ans += 2 * sum > total;
        sum += peldarquin[(i + h) % n] - peldarquin[i];
    }

    return ans;
}