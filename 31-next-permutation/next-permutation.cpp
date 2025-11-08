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


// | Step | What?            | Why?                                                                     |
// | ---- | ---------------- | ------------------------------------------------------------------------ |
// | 1    | Find suffix      | Locate part where change is needed to get next permutation               |
// | 2    | Find pivotk      | Smallest possible increase                                               |
// | 3    | Find swap indexl | Ensure increase is minimal                                               |
// | 4    | Swap             | Move to new permutation                                                  |
// | 5    | Reverse suffix   | Make tail minimal, ensuring it’s the next permutation (not skipping any) |