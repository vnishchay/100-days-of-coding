class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0 ; int r=  h.size()-1;  int lmax = INT_MIN; int rmax = INT_MIN; 
        int total = 0; 
        while(l < r) {
             lmax = max(h[l], lmax); 
             rmax = max(h[r], rmax); 
             total += (lmax < rmax) ? lmax - h[l++] : rmax - h[r--]; 
        }
        return total ; 
    }
};