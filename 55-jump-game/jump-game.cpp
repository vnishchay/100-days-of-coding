class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0; 
        if(nums.size() == 1) return true; 
        for(int i = 0; i < nums.size(); i ++) {
              mx = max(i + nums[i], mx); 
              if(mx <= i) return false; 
              if(mx >= nums.size()-1) return true; 
        }
        return false; 
    }
};