class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {
        stack<int> st; 
        unordered_map<int,int> mp; 

        int sz = nums.size()-1; 
        while(sz >= 0) {
            if(st.empty()) {
                mp[nums[sz]] = -1;
                st.push(nums[sz]);
            }else {
            if(st.top() <= nums[sz]){
            while(!st.empty() && st.top() <= nums[sz]){
                st.pop(); 
            }
            mp[nums[sz]] = st.empty() ? -1 : st.top(); 
            st.push(nums[sz]); 
            }else {
                 mp[nums[sz]] = st.top(); 
                 st.push(nums[sz]); 
            }
            }
            sz --; 
        }
        for(int i = 0; i < nums1.size(); i ++){
            nums1[i] = mp[nums1[i]]; 
        }
        return nums1; 
    };
};