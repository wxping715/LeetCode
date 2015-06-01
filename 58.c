int lengthOfLastWord(char* s) {
    int cnt = 0, len = strlen(s);
    
    if(len == 0) return 0;
    bool first = true;
    
    for(int i = len-1;i >= 0;i--){
        
        if(first){
            if(s[i] == ' ') continue;
            else{
                first = false;
                cnt++;
            }
        }else{
            if(s[i] != ' ') cnt++;
            else return cnt;
        }
    }
    
    return cnt;
}
