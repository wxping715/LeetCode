class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        
        vector<int> res;
        vector<int> orderlist;
        int tmp;
        
        copy(numbers.begin(),numbers.end(),back_inserter(orderlist));
        
        sort(orderlist.begin(),orderlist.end());
        for(int i = 0;i < numbers.size();i++)
        {
            tmp = binarySearch(orderlist,target-numbers[i]);
            if(tmp < 0) continue;
            
            tmp = findOriginalIndex(numbers,orderlist[tmp]);
            if(tmp == i+1) continue;
            
            res.push_back(i+1);
            tmp > i + 1 ? res.insert(res.begin()+1,tmp) : res.insert(res.begin(),tmp);
            return res;
        }
    }
    
    int binarySearch(vector<int> &numbers,int x){
        int l = 0,r = numbers.size() - 1,mid;
        while(l <= r){
            mid = (l+r)/2;
            if(numbers[mid] < x) l = mid + 1;
            else if(numbers[mid] > x) r = mid - 1;
            else return mid;
        }
        return -1;
    }
    
    int findOriginalIndex(vector<int> numbers,int x){
        for(int i = 0;i < numbers.size();i++){
            if(numbers[i] == x) return i+1;
        }
    }
};