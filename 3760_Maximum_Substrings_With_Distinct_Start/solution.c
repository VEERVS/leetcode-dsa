int maxDistinct(char* s) {
    int freq[26] = {0};
    int count = 0;

    for(int i=0; s[i]!='\0'; i++){
        if(freq[s[i] - 'a'] == 0){
            freq[s[i] - 'a'] = 1;
            count++;
        }
    }
    return count;
}