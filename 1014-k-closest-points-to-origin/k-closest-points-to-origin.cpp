class Solution {
public:
    int calculateEuclidian(int x, int y){
        return x*x + y*y; 
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq; 
        vector<vector<int>> result; 
        for(auto a : points) {
            int dist = calculateEuclidian(a[0], a[1]); 
            pq.push({dist, a}); 
            while(pq.size()> k) pq.pop();
        }
        while(pq.size()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result; 
    }
};