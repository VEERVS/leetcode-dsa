// bool isPalindrome(int x) {
//     if(x<0){
//         return false; 
//     }else{
//         long long rem, rev=0, temp=x;
//         while(temp!=0){
//             rem = temp%10;
//             rev = (rev*10) + rem;
//             temp /= 10;
//         }
//         return x==rev;
//     }
// }
bool isPalindrome(int x) {
    if(x<0 || (x%10==0 && x!=0)){
        return false;
    }
    int rev = 0;
    while(x>rev){
        rev = (rev*10) + (x%10);
        x/=10;
    }
    return x==rev || x==rev/10;
}