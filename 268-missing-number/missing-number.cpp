class Solution {
public:
    int op(int a, int b) {
        return a+b; 
    }
    int missingNumber(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0); 
        int sz= nums.size();
        return ((sz*sz+sz)/2) - sum; 
    }
};