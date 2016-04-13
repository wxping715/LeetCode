class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> v;
        if(nums.size() == 0) return v;
        
        int s = nums[0],r = s;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] != (r+1)){
                v.push_back(get_range(s,r));
                s = nums[i];
            }
            r = nums[i];
        }
        v.push_back(get_range(s,r));
        return v;
    }
    
    string get_range(int s, int r){
        stringstream ss;
        ss<<s;
        string s_str = ss.str();
        ss.str("");
        
        if(s == r) return s_str;
        ss<<r;
        return s_str+"->"+ss.str();
    }
};
