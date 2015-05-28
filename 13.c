int hash[256];
void init()
{
    hash['I'] = 1;
    hash['V'] = 5; 
    hash['X'] = 10;
    hash['L'] = 50;
    hash['C'] = 100;
    hash['D'] = 500;
    hash['M'] = 1000;
}

int romanToInt(char* s) {
    init();

    int sum = 0,len = strlen(s);
    sum = hash[*(s+len-1)];
    int pre = sum;

    for(int i = len-2;i >= 0;i--){
        int val = hash[*(s+i)];

        if(val >= pre){
            sum += val;
        }else{
            sum -= val;
        }
        pre = val;
    }
    return sum;
}
