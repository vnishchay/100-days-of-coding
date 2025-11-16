class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int v = 0;
        int mx = INT_MIN; 
        for(int i = 0 ; i < nums.size(); i ++) {
            if(nums[i] == 1){
                v+=1;
            }else {
                mx = max(v, mx); 
                v = 0;
            }
        }
        mx = max(v,mx); 
        return mx; 
    }
};