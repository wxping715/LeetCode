int MAX_INT = 2147483647;
int _MAX_INT = 2147483648;

char _MAX_CHAR[15] = "2147483648";
char MAX_CHAR[15] = "2147483647";
char number[500];
int convert(char* s,int flag){
    
    int max_int = MAX_INT;
    char* max_char = MAX_CHAR;
    if(flag == -1){
        max_int = _MAX_INT;
        max_char = _MAX_CHAR;
    }
    
    int len = strlen(s);
    if(len > 10) return max_int;
    else if(len == 10){
        for(int i = 0;i < len;i++)
            if(*(s+i) > *(max_char+i)) return max_int;
            else if(*(s+i) < *(max_char+i)) break;
    }
    
    int ans = 0;
    for(int i = 0;i < len;i++)
        ans = ans * 10 + *(s+i) - '0';
    return ans;
}

int myAtoi(char* str) {
    
    int cnt = 0,i = 0;
    int flag = 1,len = strlen(str);
    bool hasflag = false;
    for(int i = 0;i < len;i++)
    {
        if(cnt == 0 && !hasflag && *(str+i) == ' ') continue;
        if(cnt == 0 && !hasflag && *(str+i) == '-'){
            flag = -1;
            hasflag = true;
            continue;
        }
        if(cnt == 0 && !hasflag && *(str+i) == '+'){
            flag = 1;
            hasflag = true;
            continue;
        }
        
        if((*(str+i) < '0' || *(str+i) > '9')) break;
        
        number[cnt++] = *(str+i);
    }
    number[cnt] = '\0';

    if(cnt == 0) return 0;
    return flag * convert(number,flag);
}
