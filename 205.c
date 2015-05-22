bool isIsomorphic(char* s, char* t) {
    char d[256] = {'0'};
    int cnt[256] = {0};
    int len = strlen(s);
    int len1 = strlen(t);

    if(len != len1) return false;
    
    for(int i = 0;i < len;i++)
    {
        if((d[*(s+i)] != 0 && d[*(s+i)] != *(t+i)) || (cnt[*(t+i)]>0) &&d[*(s+i)] == 0)
            return false;
        
        d[*(s+i)]=*(t+i);
        cnt[*(t+i)]++;
    }
    return true;
}
