bool isValid(char *s) {
    int len = strlen(s);
    
    char *stack = (char *)malloc(len*sizeof(char));
    int p = -1;
    for(int i = 0;i < len;i++){
        
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            *(stack+(++p)) = s[i];
        else if(p < 0) return false;
        else if(s[i] == ')'){
            if(*(stack+p) == '(') p--;
            else return false;
        }
        else if(s[i] == ']'){
            if(*(stack+p) == '[') p--;
            else return false;
        }
        else if(s[i] == '}'){
            if(*(stack+p) == '{') p--;
            else return false;
        }
    }
    
    if(p < 0) return true;
    return false;
}