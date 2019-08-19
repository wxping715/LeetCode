class Solution {
    
    // my nlogn algorithm
//     public int numFriendRequests(int[] ages) {
//         Arrays.sort(ages);
//         int ans = 0;
//         // a/2+7<B<=A
//         int repeated = 1;
//         for (int i = 0; i < ages.length; i++) {
//             if (i+1 < ages.length && ages[i] == ages[i+1]) {
//                 repeated++;
//                 continue;
//             }
            
//             int low = ages[i]/2 + 7;
//             if (low >= ages[i]) continue;
//             int firstLarge = binarySearch(ages, 0, i, low);
//             ans += repeated * (i - firstLarge);
//             repeated = 1;
//         }
//         return ans;
//     }
    
//     private int binarySearch(int[] ages, int s, int e, int key) {
//         int l = s, r = e;
//         while (l < r) {
//             int m = (r-l)/2 + l;
//             if (ages[m] <= key) l = m + 1;
//             else r = m;
//         }
//         return l;
//     }
    
    public int numFriendRequests(int[] ages) {
        int[] ageCount = new int[121];
        int[] ageSum = new int[121];
        
        int ans = 0;
        // 0.5A + 7 < B <= A, so A > 0.5A+7, then A > 14
        int sum = 0;
        for (int age : ages) 
            ageCount[age]++;
        
        for (int i = 15; i <= 120; i++) {
            sum += ageCount[i];
            ageSum[i] = sum;
            if (ageCount[i] > 0) {
                // they can't send requests to themselves
                ans += (ageSum[i] - ageSum[i/2+7] - 1) * ageCount[i];
            }
        }
        return ans;
    }
}
