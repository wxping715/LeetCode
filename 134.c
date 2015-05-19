int canCompleteCircuit(int gas[], int cost[], int n) {
    int min = 99999999;
    int sum = 0, sindex;
    
    for(int i = 0;i < n;i++)
    {
        sum += gas[i] - cost[i];
        if(sum < min){
            min = sum;
            sindex = i;
        }
    }
    
    if(sum >= 0) return (sindex+1)%n;
    return -1;
}