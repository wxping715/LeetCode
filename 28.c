int strStr(char* haystack, char* needle) {
    int lens = strlen(haystack);
    int lent = strlen(needle);
    
    if(lent > lens) return -1;
    
    for(int i = 0;i < lens - lent + 1;i++)
    {
        int j;
        for(j = 0;j < lent; j++)
            if(*(haystack+i+j) != *(needle+j))
                break;
        if(j >= lent) return i;
    }
    return -1;
}
