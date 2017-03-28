class Solution {
public:

    // basic version
    /*int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (string time : timePoints)
            minutes.push_back(stoi(time.substr(0,2))*60 + stoi(time.substr(3,2)));
        sort(minutes.begin(), minutes.end());
        
        int mindiff = minutes.front() + 1440 - minutes.back();
        for (int i = 1; i < minutes.size(); i++)
            mindiff = min(minutes[i] - minutes[i-1], mindiff);
        return mindiff;
    }*/
    
    // advanced version: use bucket to sort
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> hashmap(24*60+1, false);
        for (string time : timePoints) {
            int m = stoi(time.substr(0,2))*60 + stoi(time.substr(3,2));
            if (hashmap[m]) return 0;
            hashmap[m] = true;
        }
        
        int first = INT_MAX, last = INT_MIN, pre = -1;
        int mindiff = INT_MAX;
        for (int i = 0; i <= 24*60; i++) {
            if (!hashmap[i]) continue;
            first = min(i, first);
            last = max(last, i);
            
            if (pre != -1) mindiff = min(mindiff, i-pre);
            pre = i;
        }
        
        mindiff = min(mindiff, first+24*60-last);
        return mindiff;
    }
    
    /*
    * 00:00 01:00 22:40
    * 0  60  1360
    * 1440 - 1360 = 80
    */
};
