class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq; 
        unordered_map<char,int>mp;
        for(auto a : s){
            mp[a]+=1;
        }

        for(auto [key, value] : mp){
            pq.push({value, key});
        }

        string st = ""; 
        while(!pq.empty()){
            auto [num, str] = pq.top();
            while(num> 0) {
                st += str;
                num --;
            }
            pq.pop();
        }
        // reverse(st.begin(), st.end());
        return st; 
    }
};