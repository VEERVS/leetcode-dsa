// int sumOfMultiples(int n) {
//     int sum=0;
//     for(int i=1; i<=n; i++){
//         if(i%3==0 || i%5==0 || i%7==0){
//             sum += i;
//         }
//     }
//     return sum;
// }
int sumOfMultiples(int n) {
    int k1=n/3, k2=n/5, k3=n/7, k4=n/15, k5=n/21, k6=n/35, k7=n/105;
    int s1 = 3 * (k1*(k1+1)/2);
    int s2 = 5 * (k2*(k2+1)/2);
    int s3 = 7 * (k3*(k3+1)/2);
    int s4 = 15 * (k4*(k4+1)/2);
    int s5 = 21 * (k5*(k5+1)/2);
    int s6 = 35 * (k6*(k6+1)/2);
    int s7 = 105 * (k7*(k7+1)/2);

    return (s1+s2+s3) - (s4+s5+s6) +s7; 
}