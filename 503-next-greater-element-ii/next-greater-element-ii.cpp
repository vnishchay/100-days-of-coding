class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st; 

        for(int i = nums.size() - 1 ; i >= 0 ; i-- ){
            st.push(nums[i]) ;
        }
        vector<int> v(nums.size(),0);
        for(int i = nums.size()-1 ; i >= 0; i --){

            while(!st.empty() && st.top() <= nums[i]){
                st.pop(); 
            }

            if(st.empty()) {
                v[i] = -1;
            }else{
                v[i] = st.top();
            }
            st.push(nums[i]);
        }
        return v;
    }
};