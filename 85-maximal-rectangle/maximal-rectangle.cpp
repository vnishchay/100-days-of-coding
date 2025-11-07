class Solution {
public:
vector<int> NSER(vector<int> arr){
    stack<int> st ;
    vector<int> v ;
    int n = arr.size() ;

    for( int i = n - 1 ; i >= 0 ; i-- ){

        while(st.size() > 0 && arr[st.top()] >= arr[i]){
            st.pop() ;
        }

        if(st.size() == 0){
            v.push_back(n) ;
        }else{
            v.push_back(st.top()) ;
        }

        st.push(i) ;
    }
    reverse(v.begin() , v.end()) ;
    return v ;
}

vector<int> NSEL(vector<int> arr){
    stack<int> st ;
    vector<int> v ;
    int n = arr.size() ;

    for( int i = 0 ; i < n ; i++ ){

        while(st.size() > 0 && arr[st.top()] >= arr[i]){
            st.pop() ;
        }

        if(st.size() == 0){
            v.push_back(-1) ;
        }else{
            v.push_back(st.top()) ;
        }

        st.push(i) ;
    }

    return v ;
}

int largestRectangleArea(vector<int>& heights) {
    vector<int> right = NSER(heights) ;
    vector<int> left = NSEL(heights) ;

    int ans = -1 ;

    for(int i=0 ;i<heights.size() ;i++){
        ans=max(ans,(right[i]-left[i]-1)*heights[i]);
    } 

    return ans ;
}

int maximalRectangle(vector<vector<char>>& nums) {

    if(nums.size() == 0){
      return 0 ;
    }
    vector<int> ds(nums[0].size(), 0) ;
    int mx = 0; 
    for(int i = 0 ; i< nums.size() ; i++ ){
      for(int j = 0 ; j<nums[i].size() ; j++ ){
        if(nums[i][j] != '0'){
          ds[j]++ ;
        }else{
          ds[j] = 0 ;
        }
      }
      mx = max(largestRectangleArea(ds) , mx);	
    }
    return mx ;
 }
};


