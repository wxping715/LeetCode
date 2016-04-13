bool isAnagram(char* s, char* t) {
    
    int l1 = strlen(s), l2 = strlen(t);
    if(l1 != l2) return false;
    
    int map[26];
    memset(map,0,sizeof(map));
    
    for(int i = 0;i < l1;i++) map[s[i]-'a']++;
    for(int i = 0;i < l2;i++){
        if(map[t[i]-'a'] <= 0) return false;
        map[t[i]-'a']--;
    }
    
    return true;
}
