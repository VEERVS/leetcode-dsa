#include<stdlib.h>

int scoreOfString(char* s) {
    int sum = 0, diff;
    for(int i=0; s[i+1]!='\0'; i++){
        diff = abs(s[i]-s[i+1]);
        sum += diff;
    }
    return sum;
}