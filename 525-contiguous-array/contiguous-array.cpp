class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> vv(nums.size(), 0); 
        vv[0] = nums[0] == 0 ? -1 : 1;  // Changed: Should be -1 for 0, not 0
        unordered_map<int,int> mp; 
        mp[vv[0]] = 0;  
        int mx = (vv[0] == 0) ? 1 : 0;  // Changed: Check if first element gives balance
        
        for(int i = 1; i < nums.size(); i++) {
            vv[i] = vv[i - 1] + (nums[i] == 0 ? -1 : 1); 

            if(vv[i] == 0) {
                mx = max(mx, i + 1);
            } else if(mp.find(vv[i]) != mp.end()) {
                mx = max(mx, i - mp[vv[i]]);  // Changed: Removed +1
            } else {
                mp[vv[i]] = i; 
            }
        }
        
        return mx; 
    }
};