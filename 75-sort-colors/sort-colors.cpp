class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = -1 ; int m = 0 ; int z = nums.size()-1;
        while(m <= z) {
            if(nums[m] == 0){
                l++; 
                swap(nums[l], nums[m]); 
                m++; 
            }else if(nums[m] == 2){
                swap(nums[z], nums[m]);
                z --; 
            }else {
                m+=1; 
            }
        }
    }
};