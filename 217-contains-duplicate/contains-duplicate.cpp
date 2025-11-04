class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // nums, true if any value appears twise in array ? 
        // mp approach. 
        unordered_map<int,int> mp; 
        for(int i = 0 ; i < nums.size(); i ++) {
            if(mp.find(nums[i]) != mp.end()) return true;
            mp[nums[i]] = i; 
        }
        return false; 
    }
};