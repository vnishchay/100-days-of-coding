class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long> , greater<long long>> pq; 
        pq.push(1);
        long long tp = 0; 
        for(int i = 0; i < n ; i ++) {
            long long top = pq.top();
            cout << top << endl ;
            tp = top;
            if(i == n) return tp;  
            while( !pq.empty() && pq.top() == tp) pq.pop();
            pq.push(2*top);
            pq.push(3*top);
            pq.push(5*top);
        }
        return int(tp); 
    }
};