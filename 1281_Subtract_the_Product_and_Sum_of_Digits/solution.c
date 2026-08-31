int subtractProductAndSum(int n) {
    int prod = 1, sum = 0, temp=n, digit;
    
    while(temp!=0){
        digit = temp%10;
        prod *= digit;
        sum += digit;
        temp/=10;
    }
    return prod-sum;
}