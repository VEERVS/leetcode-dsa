int reverseDegree(char* s) {
    int sum = 0, i;
    for(i=0; s[i]!='\0'; i++){
        sum += (26 - (s[i] - 'a')) * (i+1);
    }
    return sum;
}