class Solution {
public:
    int maxProfit(vector<int>& prices) {
        pair<int,int> mn = {INT_MAX, -1}; 
        pair<int,int> mx = {INT_MIN, -1}; 
        int total = 0; 

        for(int i = 0; i < prices.size(); i ++) {
            if(mn.first> prices[i]){
                mn = {prices[i], i};
            }

            if(prices[i] >= mx.first && i > mn.second || prices[i] - mn.first > total && i > mn.second ){
                mx = {prices[i], i}; 
                total = max(mx.first - mn.first, total); 
            }

        }
        return total; 
    }
};