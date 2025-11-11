class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn = INT_MAX ; 
        int mx = 0;
        int smx = -1; 
        int mxx = INT_MIN;  

        for(int i = 0 ; i < nums.size(); i ++) {
            if(mn > nums[i]){
                mn = nums[i];
                smx = i; 
            }

            if(i > smx && nums[i] > mn){
                 mxx = max(nums[i] - mn, mxx); 
            }
        }
        return mxx == INT_MIN ? -1 : mxx;
    }
};