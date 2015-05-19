int abs(int a){ return a > 0 ? a : -a;}
bool ischar(char a){ return ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')); }
bool isnum(char a){ return (a >= '0' && a <= '9'); }

bool isPalindrome(char *s) {
    
    int len = strlen(s);
    
    int i = 0, j = len - 1;
    while(i < j){
        
        while(i < len && !ischar(*(s+i)) && !isnum(*(s+i))) i++;
        while(j >= 0 && !ischar(*(s+j)) && !isnum(*(s+j))) j--;
        
        if(j < 0 || i >= len) return true;
        
        if(i >= j) return true;
        if(ischar(*(s+i)) && ischar(*(s+j))){
            if(abs(*(s+i)-*(s+j)) != 32 && abs(*(s+i)-*(s+j)) != 0) return false;   
        }
        else if(isnum(*(s+i)) && isnum(*(s+j))){
            if(*(s+i) != *(s+j)) return false;
        }
        else return false;
        
        i++;j--;
    }
    return true;
}