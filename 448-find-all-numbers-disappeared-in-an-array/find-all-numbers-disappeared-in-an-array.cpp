class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<int> nonexist; 
        unordered_map<int,int>mp; 
        for(auto a: nums) mp[a]+=1; 
        for(int i = 1; i <= nums.size(); i ++){
            if(mp.find(i) == mp.end()) nonexist.push_back(i);
        }
        return nonexist; 
    }
};