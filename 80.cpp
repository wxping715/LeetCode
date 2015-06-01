class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre = 0x3f3f3f3f,cnt = 0,index = 0;
        
        while(index < nums.size()){
            if(pre == nums[index]){
                if(cnt < 2)  cnt++;
                else{ 
                    nums.erase(nums.begin()+index);
                    continue;
                }
            }
            else{
                pre = nums[index];
                cnt=1;
            }
            index++;
        }
        return nums.size();
    }
};
