class Solution {
public:
    // temps , answer -> ans[i] number of days you have to wait after ith day to get warmer tmep; 
    // for each i loop over i+1-> end to find the warmer temp
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        vector<int> vv;  
        for(int i = t.size()-1; i >=0; i --){
            while(!st.empty() && t[st.top()] <= t[i]) {
                st.pop();
            }

            if(st.empty()) {
                vv.push_back(0);
            }else{
                vv.push_back(st.top() - i);
            }
            st.push(i);
        }
        reverse(vv.begin(), vv.end());
        return vv; 
    }
};