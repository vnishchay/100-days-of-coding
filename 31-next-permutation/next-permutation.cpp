class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size()-2;
        while(k >= 0 && nums[k] >= nums[k+1]) k--; 

        if(k < 0) {
            reverse(nums.begin(), nums.end()); 
            return ;
        }

        int l=k ;
        for(int i = nums.size()-1 ; i>=k; i--){
            if(nums[k] < nums[i]){
                l = i; 
                break; 
            }
        }

        swap(nums[l], nums[k]);

        reverse(nums.begin()+ k + 1, nums.end());
        return; 
    }
};